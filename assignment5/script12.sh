#!/bin/bash

if [ -z "$1" ]; then
    echo "Usage: $0 <filename>"
    exit 1
fi

if [ -f "$1" ]; then
    last_modified=$(date -r "$1" +'%Y-%m-%d %H:%M:%S')
    echo "Last modification time of $1: $last_modified"
else
    echo "File '$1' does not exist."
fi
