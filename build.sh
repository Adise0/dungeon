#!/usr/bin/env bash
set -euo pipefail

printf "Checking folders...\n"
mkdir -p out

printf "Starting watcher...\n"

watchexec -w src -e cpp,h -r --stop-signal SIGTERM -- bash -lc '
  clear
  set -e
  tmp="./out/app.$$.new"
  g++ $(find src -type f -name "*.cpp") -std=c++20 -Wall -O2 -o "$tmp" $(pkg-config --cflags --libs sdl3 sdl3-image)
  mv -f "$tmp" ./out/app
  exec ./out/app
'

printf "Done: ./out/app\n"
