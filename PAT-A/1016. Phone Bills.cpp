#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
struct Call
{
	string name;
	int month;
	int date;
	int hour;
	int minute;
	int total;
	string status;
};
int charge[24];
vector<Call> all_calls;
vector<Call> format_calls;
bool compare(Call a,Call b)
{
	if(a.name < b.name)
		return 1;
	else if(a.name == b.name && a.total < b.total)
		return 1;
	else
		return 0;
}
void show(Call c)
{
	cout<<c.name<<" ";
	cout<<c.month<<":"<<c.date<<":"<<c.hour<<":"<<c.minute<<" ";
	cout<<c.status<<endl;
}
//calculate money from the begin of month to the time given
int chargeByTime(int time)
{
	int hours = time/60;
	int minutes = time%60;
	int money = 0;
	int i;
	for(i = 0;i<hours;i++)
		money += charge[i%24]*60;
	money += charge[i%24]*minutes;
	return money;
}
double calCost(Call s,Call t)
{
	return (double)(chargeByTime(t.total)-chargeByTime(s.total))/100;
}
int calLast(Call s,Call t)
{
	return (t.date-s.date)*24*60+(t.hour-s.hour)*60+(t.minute-s.minute);
}
int main()
{
	for(int i = 0;i<24;i++)
		cin>>charge[i];
	int N;
	cin>>N;
	while(N--)
	{
		Call c;
		cin>>c.name;
		cin>>c.month;
		getchar();
		cin>>c.date;
		getchar();
		cin>>c.hour;
		getchar();
		cin>>c.minute;
		c.total = c.minute + 60*c.hour + 24*60*c.date;
		cin>>c.status;
		all_calls.push_back(c);
	}
	sort(all_calls.begin(),all_calls.end(),compare);

	//filter delete those bad record
	bool haveonline = false;
	string curname;
	for(int i=0;i<all_calls.size();i++)
	{
		if(haveonline == false && all_calls[i].status =="on-line" )
		{
			format_calls.push_back(all_calls[i]);
			haveonline = true;
			curname = all_calls[i].name;
		}
		else if(haveonline == true && all_calls[i].status =="on-line")
		{
			format_calls.pop_back();
			format_calls.push_back(all_calls[i]);
			haveonline = true;
			curname = all_calls[i].name;
		}
		else if(haveonline == true && all_calls[i].status =="off-line"&&all_calls[i].name ==curname)
		{
			format_calls.push_back(all_calls[i]);
			haveonline = false;
		}
	}
	//the last must be offline
	if((*(format_calls.end()-1)).status == "on-line")
		format_calls.pop_back();

	//output
	double totalcost = 0;
	curname = "";
	for(int i=0;i<format_calls.size();i+=2)
	{
		if(format_calls[i].name != curname)
		{
			if(curname!="")
			{
				printf("Total amount: $%.2f\n",totalcost);
				totalcost = 0;
				printf("%s %02d\n",format_calls[i].name.c_str(),format_calls[i].month);
			}
			else
			{
				printf("%s %02d\n",format_calls[i].name.c_str(),format_calls[i].month);
			}
			curname = format_calls[i].name;
		}
		printf("%02d:%02d:%02d",format_calls[i].date,format_calls[i].hour,format_calls[i].minute);
		printf(" ");
		printf("%02d:%02d:%02d",format_calls[i+1].date,format_calls[i+1].hour,format_calls[i+1].minute);
		printf(" ");
		printf("%d",calLast(format_calls[i],format_calls[i+1]));
		printf(" ");
		printf("$%.2f\n",calCost(format_calls[i],format_calls[i+1]));
		totalcost+=calCost(format_calls[i],format_calls[i+1]);
	}
	printf("Total amount: $%.2f\n",totalcost);
}
