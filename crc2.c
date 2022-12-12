  #include <stdio.h>
#include<string.h>
char data[50],divi[50],temp[100],total[100];
int datalen,len,divlen,flag=0,j,i;
void check();

void main()
{
    	printf("\nEnter data at sender site:");
    	gets(data);
    	printf("\nEnter polynomial:");
    	gets(divi);
    	datalen=strlen(data);
    	divlen=strlen(divi);
    	len=datalen+divlen-1;

    	for(i=0;i<datalen;i++)
    	{
    		temp[i]=data[i];
        		total[i]=data[i];
    	}

    	for(i=datalen;i<len;i++)
    	{
        		total[i]='0';
    	}

    	check( );

    	printf("remainder on sender side is : %s" ,data);
    	for(i=0;i<divlen;i++)	 // append crc output(remainder) at end of temp
	  	temp[i+datalen]=data[i];

 	printf("\nTransmitted Code Word:%s",temp);
	printf("\n\nEnter the received code word:");
    	gets(total);

 	check();

 	printf("remainder on receiver side is : %s" ,data);
	for(i=0;i<divlen-1;i++)
	{
		if(data[i]=='1')
		{
			flag=1;
			break;
		}
	}

	if(flag==1)
	{
	    printf("\nErrors");
	}
	else if(flag==0)
	{
	    printf("\nSuccess");
	}
}
void check()
{
	 for(j=0;j<divlen;j++)
	 {
        		data[j]=total[j];
	 }

    	while(j<=len)
	{
        		if(data[0]=='1')
        		{
			for(i = 1;i <divlen ; i++)
			{
   				data[i] = (( data[i] ==divi[i])?'0':'1');
			}
        		}

        		for(i=0;i<divlen-1;i++)
        		{
            		data[i]=data[i+1];
        		}

       		 data[i]=total[j++];
    	}
}
