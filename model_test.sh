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

echo "# ${BOLD}sshared ${NC} model tests"
echo

echo " ${BOLD_GREEN}[RUN]${NC} ${BOLD}Model tests${NC}"
./stest > output 2> errout
echo
echo "${BOLD_BLUE} --> output${NC}"
echo
cat output

if [ -s errout ]
then
    echo
    echo "${BOLD_MAGENTA} --2> error output${NC}"
    echo
    cat errout
fi

echo
echo " -- ${MAGENTA} cleanup${NC} -- "
echo
rm test.txt
