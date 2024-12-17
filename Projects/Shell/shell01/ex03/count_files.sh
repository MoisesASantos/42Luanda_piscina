#!/bin/bash

total=$(($(find . -type f | wc -l) + $(find . -type d | wc -l)))
echo "$total"
