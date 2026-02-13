#!/usr/bin/env bash
set -euo pipefail

printf "Checking folders...\n"
mkdir -p out

printf "Starting watcher...\n"

watchexec -w src -e cpp,h -r --stop-signal SIGTERM -- bash -lc '
  clear
  set -e
  tmp="./out/app.$$.new"
  files=$(find src -type f -name "*.cpp" -print)
  g++ $files -std=c++20 -Wall -O2 -o "$tmp"
  mv -f "$tmp" ./out/app
  exec ./out/app
'

printf "Done: ./out/app\n"
