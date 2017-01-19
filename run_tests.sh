# constant colors
BOLD='\033[1m'
BOLD_GREEN='\033[1;32m'
GREEN='\033[32m'
BOLD_BLUE='\033[1;34m'
BLUE='\033[34m'
BOLD_MAGENTA='\033[1;35m'
MAGENTA='\033[35m'
NC='\033[0m'

echo "# ${BOLD}sshared ${NC}tests"
echo

echo " ${BOLD_GREEN}[RUN]${NC} ${BOLD}help information${NC}"
./stest -h > output 2> errout
echo "${BOLD_BLUE} --> output${NC}"
cat output

if [ -s errout -o ]
then
    echo
    echo "${BOLD_MAGENTA} --2> error output${NC}"
    cat errout
fi

echo
echo " ${BOLD_GREEN}[RUN]${NC} ${BOLD}incorrect filter message${NC}"
./stest split -in my.file -n  > output 2> errout
echo "${BOLD_BLUE} --> output${NC}"
cat output

if [ -s errout -o ]
then
    echo
    echo "${BOLD_MAGENTA} --2> error output${NC}"
    cat errout
fi

echo
echo " ${BOLD_GREEN}[RUN]${NC} ${BOLD}correct filter message${NC}"
./stest split -in my.file -t 3 -n 5 > output 2> errout
echo "${BOLD_BLUE} --> output${NC}"
cat output

if [ -s errout -o ]
then
    echo
    echo "${BOLD_MAGENTA} --2> error output${NC}"
    cat errout
fi

echo
echo " -- ${MAGENTA} cleanup${NC} -- "
rm test.txt
