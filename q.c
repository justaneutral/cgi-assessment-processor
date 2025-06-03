#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXFIELDOFENDEAVOR 64
//#include "alldata.h"

#define QUESTION_PREFIX "<br><br><div style=\"margin-left: 40px;\"><div style=\"margin-left: 40px;\">"
#define ANSWER_PREFIX "<br></div><div style=\"margin-left: 40px;\">"
int main(void)
{
	int i,j;
	char *data=NULL;
	char question_number='a';
	char new_question_number='a';
	char prev_question_number='a';
	char score='a';
	char fieldofendeavor[65]="";
	const char *buffer[]={
"You are an extraordinary ability individual in:<br><br><select name=""choice""><option selected=\"selected\">Please choose from the list below</option><option>Science</option><option>Art</option><option>Sport</option><option>Dance</option><option>Engineering</option><option>Business</option><option>None of the above</option></select>",

"Describe your field. Use latin letters and blanks:<br><br><input name=\"field\" size=\"64\">",

"Have you received prizes or awards related to your field of endeavor?<br><br><select name=\"prizes\"><option selected>Please choose from the list below<option>Yes<option>No</select>",

"Are you a member of an association, group, team or a similar community related to your field of endeavor?<br><br><select name=\"member\"><option selected>Please choose from the list below<option>Yes<option>No</select>",

"Does this association, group, team or community require outstanding achievement of its members, as judged by recognized experts?<br><br><select name=\"require\"><option selected>Please choose from the list below<option>Yes<option>No</select>",

"Are there any printed references to your work in major trade publications, professional publications or major media?<br><br><select name=\"publications\"><option selected>Please choose from the list below<option>Yes<option>No</select>",

"Are there any citations to your work in major trade publications, professional publications or major media?<br><br><select name=\"publications\"><option selected>Please choose from the list below<option>Yes<option>No</select>",

"Have you ever judged the work of others in your field of endeavor?<br><br><select name=\"judged\"><option selected>Please choose from the list below<option>Yes<option>No</select>",

"Have you participated in a review panel, editorial board, or have you reviewed the work of others in your field of endeavor?<br><br><select name=\"reviewed\"><option selected>Please choose from the list below<option>Yes<option>No</select>",

"Do you think you have made a contribution of major significance to your field of endeavor?<br><br><select name=\"contribution\"><option selected>Please choose from the list below<option>Yes<option>No</select>",

"Have you authored any published works related to your field of endeavor?<br><br><select name=\"authored\"><option selected>Please choose from the list below<option>Yes<option>No</select>",

"Has your work been exhibited or showcased?<br><br><select name=\"exhibited\"><option selected>Please choose from the list below<option>Yes<option>No</select>",

"Have you acted in a leading or critical role in organization of distinguished reputation related to your field of endeavor?<br><br><select name=\"leading\"><option selected>Please choose from the list below<option>Yes<option>No</select>",

"Have you received high remuneration (compensation, wages, income) for your activities compared to others in your field of endeavor?<br><br><select name=\"remuneration\"><option selected>Please choose from the list below<option>Yes<option>No</select>",

"Have you achieved commercial success in your field of endeavor?<br><br><select name=\"commercial\"><option selected>Please choose from the list below<option>Yes<option>No</select>",

"Congratulations!<br><br>You may qualify to file an I-140 immigrant visa petition as an alien of extraordinary ability in %s.<br> In order to have our immigration attorney, Tatiana S. Aristova, to review your case to further determine if you should indeed file I-140 immigrant visa petition as an alien of an extraordinary ability and whether we will be able to represent you in this filing, please click here.",

"Do not bother. Work more.Cheers. Come back not earlier than in several years."
	};
	//read what was sent from the form.
	data = getenv("QUERY_STRING");

        if(data!=NULL && strstr(data,"history="))
        {
		question_number=data[8];
		prev_question_number=data[9];
		score=data[10];
		for(i=0;i<MAXFIELDOFENDEAVOR && '&'!=data[i+11];i++)
		{
			fieldofendeavor[i]=data[i+11];
			if((data[i+11]>='a' && data[i+11]<='z')||(data[i+11]>='A' && data[i+11]<='Z'))
				fieldofendeavor[i]=data[i+11];
			else
				fieldofendeavor[i]=' ';
		}
		fieldofendeavor[i+1]=0;        
	}
	else //or start from the beginning.
	{
		//printf("<html>question number = %c\n", question_number+'0');
		question_number='a';
		prev_question_number=question_number;
		score='a';
		//for(i=0;i<MAXFIELDOFENDEAVOR;i++)
		//{
		//	fieldofendeavor[i]='8';
		fieldofendeavor[0]=0;
		//}
	}

	//check if must skip a question.
        if((question_number=='b' && !strstr(data,"choice=None"))||
	   (question_number=='e' && strstr(data,"member=No"))||
	   (question_number=='g' && strstr(data,"publications=No"))||
	   (question_number=='i' && strstr(data,"judged=No"))	
 	  )
        {
		question_number++;
	}
	
	//extract fieldofendeavor.
	if(question_number=='b' || question_number=='c')
	{
		for(i=0;(i<strlen(data))&&('&'!=data[i]);i++);
		for(j=i+1;(j<strlen(data))&&('='!=data[j]);j++);
		for(i=0;(i+j+1)<strlen(data);i++)
		{
			if((data[i+j+1]>='a' && data[i+j+1]<='z')||(data[i+j+1]>='A' && data[i+j+1]<='Z'))
				fieldofendeavor[i]=data[i+j+1];
			else
				fieldofendeavor[i]=' ';
		}
		fieldofendeavor[i+1]=0;
	}

	//check if prev question was answered.
	if(strstr(data,"Please")||(question_number=='c' && prev_question_number=='b' && 1>=strlen(fieldofendeavor)))
	{
		new_question_number=question_number;
		question_number=prev_question_number;
	}
	else
	{
		new_question_number=question_number+1;
		prev_question_number=question_number;
	}
	


	//check if score must go up.
	if(question_number!='d' && strstr(data,"=Yes"))
	{
		score++;
	}

	//check if score is high enough and show congr. screen
        if(question_number>='p')
	{
		if(score>='c')
		{
			question_number='p';
			new_question_number='a';
			prev_question_number='a';
		}
		else
		{
			question_number='q';
			new_question_number='a';
			prev_question_number='a';
		}
	}

	//setup form
	//printf("%s%c%c\n","Content-Type:text/html;charset=iso-8859-1",13,10);
        printf("%s%c%c\n","Content-Type:text/html;charset=ASCII",13,10);
	printf("<html><header>&#169Tatiana Aristova, Esq. <br><br><br></header><div style=\"text-align: center;\"><header style=\"font-family: Garuda; color: rgb(0, 0, 63);\"><big><big><big><span style=\"font-style: italic;\">EXTRAORDINARY ABILITY CALCULATOR</span></big></big></big></header><br><header></header></div><header><br><br>%s",QUESTION_PREFIX);
	switch(question_number)
	{
	case 'p': //successfully completed.
		printf("Your result:<br></header>");
        	printf("<body><form action=\"http://www.eb1now.com/cgi/q.cgi\">");
		//print positive conclusion.
		printf("<div><label><H3>Congratulations!</H3><br>You may qualify to file an I-140 immigrant visa petition as an alien of extraordinary ability in %s.<br><br>In order to have our immigration attorney, Tatiana S. Aristova, to review your case to further determine if you should indeed file I-140 immigrant visa petition as an alien of an extraordinary ability and whether we will be able to represent you in this filing, please click here.</label></div>",fieldofendeavor);
	break;
	case 'q': //unsuccessfull completion.
                printf("Your result:<br></header>");
                printf("<body><form action=\"http://www.eb1now.com/cgi/q.cgi\">");
                //print negative conclusion.
                printf("<div>It looks like you probably may not qualify to file an I-140 immigrant visa petition as an alien of extraordinary ability in %s, but we can suggest other visa categories that correspond to your situation.<br><br>In order to have our immigration attorney, Tatiana S. Aristova, to review your situation and determine if you should indeed file I-140 immigrant visa petition as an alien of an extraordinary ability and whether we will be able to represent you in this filing, please click here.</label></div>",fieldofendeavor);
	break;
	default:
                printf("Question %d</header><br><br>", question_number-'a'+1);
                printf("<body><form action=\"http://www.eb1now.com/cgi/q.cgi\">");

                //send parameters to the future
                printf("<input type=\"hidden\" name=\"history\" value=\"%c%c%c",new_question_number, prev_question_number, score);
		for(i=0;i<MAXFIELDOFENDEAVOR && fieldofendeavor[i];i++)
		{
			printf("%c",fieldofendeavor[i]);
		}
		printf("\">");

                //print question.
                printf("<div><label>%s</label></div>",buffer[question_number-'a']);

	}
	printf("<div><br><br><input type=\"submit\" value=\"Continue\"></div>");
		
	//debug	
	//printf("<div><input type=\"reset\" value=\"{<<%s>>((%d,%d))}\"></div>",data,sizeof(data),(int)(strstr(data,"&")-data));
	
	//if(question_number>='b')
	//	printf("<input type=\"hidden\" name=\"fieldofendeavor\" value=\"%s\">",fieldofendeavor);

	printf("</form></body></html>");
	
	return 0;
}

