#!/bin/bash

res=$(echo $1 | ~/rtol/fix2)
res2=$(echo $res | sed -E "s:^$HOME:~:")

echo $res2

