#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//NX is the number of existing date ranges for quotes requested in the past.
//NR is the number of date ranges in the incoming requests for quotes.
//determine which parts of the required date ranges have not yet been

const int N = 147000;
class Calendar
{
public:
Calendar() {
fill(begin(c), end(c), 0); // set 0
}
void addQuote(int start, int end) {
// Method to add periods and quotes to the calendar fillDays(start, end, 2);
}
void addPeriod(int start, int end) {
// Methods to add periods and quotes to the calendar fillDays(start, end, 1);
}
void printQuotes() { //print the quotes in the calendar
bool no_quotes = true;
for (int i = 0; i < N; i++) {  if (c[i] > 1) { //checks if the the day has a
quote  no_quotes = false;
 get_date(i);
 if (c[i + 1] < 2) { //check if the next day does not have a quote  cout <<
endl;
 } else {
 cout << " to ";
 for (int j = i; c[j] > 1; j++) {
 i = j;
 }
 get_date(i);
 cout << endl;
 }
 }
}
if (no_quotes) {
 cout << "No additional quotes are required." << endl; }
}
private:
int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; char c
[N]; // calendar


bool leap(int y)
{
return y % 400 == 0 || (y % 4 == 0 && y % 100 != 0);
}
void get_date(int day) {
int y, m;
for (y = 1700; day > 365 + leap(y); y++)
{ //year calculation  day -= 365 + leap(y);
}
for (m = 1; day > days[m] + (m == 2 && leap(y)); m++)
{ // month calculation
 day -= days[m] + (m == 2 && leap(y));
}
cout << m << '/' << day << '/' << y;
}
int dateToDay(int x) {
int y = x / 10000;
int m = (x % 10000) / 100;
int d = x % 100;
int day_count = 0;
for (int i = 1700; i < y; i++) {
 day_count += 365 + leap(i);
}
for (int i = 1; i < m; i++) {
 day_count += days[i] + (i == 2 && leap(y));
}
day_count += d;
return day_count;
}
void fillDays(int start, int end, int value)
{
int startDay = dateToDay(start);
int endDay = dateToDay(end);
fill(c + startDay, c + endDay + 1, value);
}
};
int main() {
int n, m, cases = 0;
while (cin >> n >> m && (n + m)) {
Calendar calendar; vector<pair<int, int>> periods(n);
for (int i = 0; i < n; i++) {
 cin >> periods[i].first >> periods[i].second;
}
for (int i = 0; i < m; i++) {
 int a, b;
 cin >> a >> b;
 calendar.addQuote(a, b);
}


for (const auto& period : periods) {  calendar.addPeriod(period.first,
period.second);
}
cout << "Case " << ++cases << ":\n"; calendar.printQuotes();
}
return 0;
}