echo "# sshared tests\n"

echo "[test] filter message..."
./sshared -in my.file -n 5 -t 3 > output
echo " - result - "
cat output
