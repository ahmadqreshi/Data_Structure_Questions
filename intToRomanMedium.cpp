
//The problem “Integer to Roman” can be solved in greedy manner where first we try to convert the number to the highest possible numeral
string intToRoman(int num) {
  string ans = "";
  vector<int> number = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
  vector<string> romanValues = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
  int index = number.size() - 1;
  while(num > 0) {
    while(number[index]<= num) {
    ans += romanValues[index];
    num -= number[index];
    }
    index--;
 }
 return ans;
}
