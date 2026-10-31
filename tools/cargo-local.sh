#!/bin/sh
set -eu
if command -v cargo >/dev/null 2>&1; then exec cargo "$@"; fi
repo_root=$(CDPATH= cd -- "$(dirname -- "$0")/.." && pwd)
tool_root=$(CDPATH= cd -- "$repo_root/../../work" && pwd)
export CARGO_HOME="$tool_root/rust-cargo"
export RUSTUP_HOME="$tool_root/rust-toolchain"
if [ ! -x "$CARGO_HOME/bin/cargo" ]; then echo 'Install Rust using rustup, then run make again.' >&2; exit 1; fi
exec "$CARGO_HOME/bin/cargo" "$@"
