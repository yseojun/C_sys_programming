#!/bin/bash

# 최적화 레벨
OPTIMIZATION_LEVELS=("O0" "O1" "O2" "O3")

# 로그 디렉토리 생성
LOG_DIR="logs"
mkdir -p "$LOG_DIR"

# print 옵션 확인
PRINT_TO_CONSOLE=false
if [ "$1" = "print" ]; then
    PRINT_TO_CONSOLE=true
fi

# 각 최적화 레벨에 대해 실행
for level in "${OPTIMIZATION_LEVELS[@]}"; do
    EXECUTABLE="./list_time_chk_$level"
    LOG_FILE="$LOG_DIR/log_$level.txt"

    # 실행 파일 존재 여부 확인
    if [ ! -f "$EXECUTABLE" ]; then
        echo "오류: $EXECUTABLE 파일이 존재하지 않습니다. 먼저 build.sh를 실행해주세요."
        exit 1
    fi

    # 실행 권한 확인 및 부여
    if [ ! -x "$EXECUTABLE" ]; then
        chmod +x "$EXECUTABLE"
    fi

    echo "실행 중: $EXECUTABLE"
    
    if $PRINT_TO_CONSOLE; then
        # 콘솔에 직접 출력
        $EXECUTABLE
    else
        # 로그 파일로 출력 리다이렉션
        $EXECUTABLE > "$LOG_FILE" 2>&1
        echo "로그 파일: $LOG_FILE"
    fi

    # 실행 결과 확인
    if [ $? -eq 0 ]; then
        echo "$EXECUTABLE 이 성공적으로 실행되었습니다."
    else
        echo "$EXECUTABLE 실행 중 오류가 발생했습니다."
        exit 1
    fi

    echo "----------------------------------------"
done

if ! $PRINT_TO_CONSOLE; then
    echo "모든 최적화 레벨에 대한 실행 완료. 로그 파일은 $LOG_DIR 디렉토리에 저장되었습니다."
fi