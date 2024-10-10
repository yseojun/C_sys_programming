#!/bin/bash

# 컴파일할 C 파일 이름
SOURCE_FILE="parallelism_test.c"

# 최적화 레벨 배열
OPTIMIZATION_LEVELS=("O0" "O1" "O2" "O3")

# 각 최적화 레벨에 대해 컴파일 수행
for level in "${OPTIMIZATION_LEVELS[@]}"
do
    gcc -$level $SOURCE_FILE -o "${level}_out"
    echo "${level} 최적화로 컴파일 완료: ${level}_out"
done

echo "모든 컴파일 작업이 완료되었습니다."