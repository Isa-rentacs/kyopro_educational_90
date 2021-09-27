#!/bin/bash
set -x
mkdir ../testcases/$1/ans
ls ../testcases/$1/in | xargs -I {} sh -c "echo {}; ./a.out < ../testcases/$1/in/{} > ../testcases/$1/ans/{}"
ls ../testcases/$1/in | xargs -I {} sh -c "echo {}; diff -b ../testcases/$1/out/{} ../testcases/$1/ans/{}"