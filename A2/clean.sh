rm *.txt
unzip S23CS2.201a-Assignment\ 2-42240.zip
find . -type f -name "*.txt" -exec mv {} . \;
find . -type d -empty -delete
mv 2021114007.txt 2021114007_bomb_defusal.txt
rm ROLLNUMBER_bomb_defusal.txt 
python3 preprocess.py