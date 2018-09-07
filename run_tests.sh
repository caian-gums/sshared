#!/bin/bash
# constant colors
BOLD='\e[1m'
BOLD_GREEN='\e[32;1m'
GREEN='\e[32m'
BOLD_BLUE='\e[34;1m'
BLUE='\e[34m'
BOLD_MAGENTA='\e[35;1m'
MAGENTA='\e[35m'
NC='\e[0m'

echo -en "# ${BOLD}sshared ${NC}tests"
echo

echo -en " ${BOLD_GREEN}[RUN]${NC} ${BOLD}help information${NC}"
./stest -h > output 2> errout
echo
echo -en "${BOLD_BLUE} --> output${NC}"
echo
cat output

if [ -s errout ]
then
    echo
    echo -en "${BOLD_MAGENTA} --2> error output${NC}"
    echo
    cat errout
fi

echo
echo -en " ${BOLD_GREEN}[RUN]${NC} ${BOLD}incorrect filter message${NC}"
./stest split -in my.file -n  > output 2> errout
echo
echo -en "${BOLD_BLUE} --> output${NC}"
echo
cat output

if [ -s errout ]
then
    echo
    echo -en "${BOLD_MAGENTA} --2> error output${NC}"
    echo
    cat errout
fi

echo
echo -en " ${BOLD_GREEN}[RUN]${NC} ${BOLD}correct filter message${NC}"
./stest split -in my.file -t 3 -n 5 > output 2> errout
echo
echo -en "${BOLD_BLUE} --> output${NC}"
echo
cat output

if [ -s errout ]
then
    echo
    echo -en "${BOLD_MAGENTA} --2> error output${NC}"
    echo
    cat errout
fi

echo
echo -en " -- ${MAGENTA} cleanup${NC} -- "
echo
rm test.txt
