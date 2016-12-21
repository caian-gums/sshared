echo "# sshared tests\n"

echo "[test] incorrect filter message..."
./sshared -in my.file -n  > output
echo " - result - "
cat output

echo "\n[test] correct filter message..."
./sshared -in my.file -n 5 -t 3 > output
echo " - result - "
cat output
