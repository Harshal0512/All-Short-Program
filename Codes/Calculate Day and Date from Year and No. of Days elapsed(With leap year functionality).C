#include<stdio.h>
#include<conio.h>

int days, year, m, s2, s3, s4;
char *month, *day;

void monthcalc(int n){
	int temp, k=1;
	temp=days;
	if(n==1){
		if(temp>31)
			temp = temp-31;
		else if(k==1){
			month="January";
			k=0;
			m=6;
		}
		if(temp>29)
			temp = temp-29;
		else if(k==1){
			month="February";
			k=0;
			m=2;
		}
		if(temp>31)
			temp = temp-31;
		else if(k==1){
			month="March";
			k=0;
			m=3;
		}
		if(temp>30)
			temp = temp-30;
		else if(k==1){
			month="April";
			k=0;
			m=6;
		}
		if(temp>31)
			temp = temp-31;
		else if(k==1){
			month="May";
			k=0;
			m=1;
		}
		if(temp>30)
			temp = temp-30;
		else if(k==1){
			month="June";
			k=0;
			m=4;
		}
		if(temp>31)
			temp = temp-31;
		else if(k==1){
			month="July";
			k=0;
			m=6;
		}
		if(temp>31)
			temp = temp-31;
		else if(k==1){
			month="August";
			k=0;
			m=2;
		}
		if(temp>30)
			temp = temp-30;
		else if(k==1){
			month="September";
			k=0;
			m=5;
		}
		if(temp>31)
			temp = temp-31;
		else if(k==1){
			month="October";
			k=0;
			m=0;
		}
		if(temp>30)
			temp = temp-30;
		else if(k==1){
			month="November";
			k=0;
			m=3;
		}
		if(temp>31)
			temp = temp-31;
		else if(k==1){
			month="December";
			k=0;
			m=5;
		}
		days=temp;
	}else{
		if(temp>31)
			temp = temp-31;
		else if(k==1){
			month="January";
			k=0;
			m=0;
		}
		if(temp>28)
			temp = temp-28;
		else if(k==1){
			month="February";
			k=0;
			m=3;
		}
		if(temp>31)
			temp = temp-31;
		else if(k==1){
			month="March";
			k=0;
			m=3;
		}
		if(temp>30)
			temp = temp-30;
		else if(k==1){
			month="April";
			k=0;
			m=6;
		}
		if(temp>31)
			temp = temp-31;
		else if(k==1){
			month="May";
			k=0;
			m=1;
		}
		if(temp>30)
			temp = temp-30;
		else if(k==1){
			month="June";
			k=0;
			m=4;
		}
		if(temp>31)
			temp = temp-31;
		else if(k==1){
			month="July";
			k=0;
			m=6;
		}
		if(temp>31)
			temp = temp-31;
		else if(k==1){
			month="August";
			k=0;
			m=2;
		}
		if(temp>30)
			temp = temp-30;
		else if(k==1){
			month="September";
			k=0;
			m=5;
		}
		if(temp>31)
			temp = temp-31;
		else if(k==1){
			month="October";
			k=0;
			m=0;
		}
		if(temp>30)
			temp = temp-30;
		else if(k==1){
			month="November";
			k=0;
			m=3;
		}
		if(temp>31)
			temp = temp-31;
		else if(k==1){
			month="December";
			k=0;
			m=5;
		}
		days=temp;
	}
}

void daycalc(){
	int temp=year;
	temp=temp/100;
	if(temp%4==0){
		s2=6;
	}
	else if(temp%4==1){
		s2=4;
	}
	else if(temp%4==2){
		s2=2;
	}
	else
		s2=0;
	temp=year%100;
	s3=temp/4;
	s4=days+m+s2+s3+temp;
	if(s4%7==0){
		day="Sunday";
	}
	else if(s4%7==1){
		day="Monday";
	}
	else if(s4%7==2){
		day="Tuesday";
	}
	else if(s4%7==3){
		day="Wednesday";
	}
	else if(s4%7==4){
		day="Thursday";
	}
	else if(s4%7==5){
		day="Friday";
	}
	else{
		day="Saturday";
	}
}

void main(){
	char *suffix;
	label:
	clrscr();
	printf("This program will calculate the day and date from just the year\nand the total no. of days elapsed in the year\n\n");
	getch();
	printf("Enter days ");
	scanf("%d", &days);
	if(days>365){
		printf("Please Enter valid days...");
		getch();
		goto label;
	}
	printf("Enter Year ");
	scanf("%d", &year);

	//leap year calculation
	if(year%4==0){
		if(year%100==0){
			if(year%400==0){
				monthcalc(1);
			}else{
				monthcalc(0);
			}
		}else{
			monthcalc(1);
		}
	}else{
		monthcalc(0);
	}
	daycalc();
	if(days%10==1){
		suffix="st";
	}
	else if(days%10==2){
		suffix="nd";
	}
	else if(days%10==3){
		suffix="rd";
	}
	else{
		suffix="th";
	}
	printf("\n%d%s of %s was %s", days, suffix, month, day);
	getch();
}