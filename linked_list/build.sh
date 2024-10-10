#!/bin/bash

# 컴파일러 설정
CC=gcc
CFLAGS="-Wall -Wextra"

# 소스 파일들
SOURCES="list_func.c list_time_chk.c"

# 최적화 레벨
OPTIMIZATION_LEVELS=("O0" "O1" "O2" "O3")

# 각 최적화 레벨에 대해 컴파일
for level in "${OPTIMIZATION_LEVELS[@]}"; do
    OUTPUT="list_time_chk_$level"
    echo "컴파일 중: $OUTPUT"
    $CC $CFLAGS -$level $SOURCES -o $OUTPUT

    # 컴파일 결과 확인
    if [ $? -eq 0 ]; then
        echo "빌드 성공: $OUTPUT"
    else
        echo "빌드 실패: $OUTPUT"
        exit 1
    fi
done

echo "모든 최적화 레벨에 대한 빌드 완료"