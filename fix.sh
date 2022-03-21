#!/bin/bash

res=$(echo $1 | ~/rtol/fix)
res2=$(echo $res | sed -E "s:^$HOME:~:")

echo $res2

