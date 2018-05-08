#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
typedef struct std{
	char name[10];
	int number;
	struct std * next;
}onestd,*p_std;
typedef struct control_std{
	p_std head;
	p_std bottom;
}* c_std;



c_std index_list(c_std index_cs){
	char index_str[10];
	scanf("%s",index_str);
	p_std index_std;
	index_std=(p_std)malloc(sizeof(onestd));
	if(index_cs->head==index_cs->bottom){
		if(strcmp(index_cs->head->name,index_str)==0){
			index_cs->head->number+=1;
		}else{
			index_cs->head->next=(p_std)malloc(sizeof(onestd));
			strcpy(index_cs->head->next->name,index_str);
			index_cs->head->next->number=1;
			index_cs->bottom=index_cs->head->next;
		}
	}else{
		for(index_std=index_cs->head;index_std!=index_cs->bottom->next;index_std=index_std->next){
			if(strcmp(index_std->name,index_str)==0){
				index_std->number+=1;
				return index_cs;
			}
		}
		index_cs->bottom->next=(p_std)malloc(sizeof(onestd));
		strcpy(index_cs->bottom->next->name,index_str);
		index_cs->bottom->next->number=1;
		index_cs->bottom=index_cs->bottom->next;	

	}
	return index_cs;
}

c_std ins_list(c_std ins_cs){
	p_std head=(p_std)malloc(sizeof(onestd));
	if(ins_cs->head==NULL){
		scanf("%s",head->name);
		head->number=1;
		
		ins_cs->head=head;
		ins_cs->bottom=head;
		
		

	}else{
		ins_cs=index_list(ins_cs);
	}
	return ins_cs;
}


int prl_list(c_std prl_cs){
	p_std prl_std;
	if(prl_cs->head==NULL){
		return 0;
	}
	if(prl_cs->head==prl_cs->bottom){
		printf("%s  %d\n",&prl_cs->head->name,prl_cs->head->number);
	}
	else{
		for(prl_std=prl_cs->head;prl_std!=(prl_cs->bottom->next);prl_std=prl_std->next){
		printf("%s  %d\n",&prl_std->name,prl_std->number);
		}
	}
	return 0;
}


void end_list(){
	exit(0);

}
c_std del_list(c_std del_cs){
	char index_str[10];
	scanf("%s",index_str);
	p_std index_std;
	p_std last_std=NULL;
	for(index_std=del_cs->head;index_std!=del_cs->bottom->next;index_std=index_std->next){
		if(strcmp(index_std->name,index_str)==0){
			if(index_std->number==1){
				if(last_std==NULL){
					del_cs->head=del_cs->head->next;
				}else{
					last_std->next=index_std->next;
				
				}
				break;
			}else{
				index_std->number-=1;
			}

		}
		last_std=index_std;
	}
	return del_cs;
}
c_std fde_list(c_std fde_cs){
	int num;
	scanf("%d",&num);
	p_std index_std;
	p_std last_std=NULL;
	for(index_std=fde_cs->head;index_std!=fde_cs->bottom->next;index_std=index_std->next){
		if(index_std->number<=num){
			if(last_std==NULL){
				fde_cs->head=fde_cs->head->next;
				
				continue;
				
			}else{
				last_std->next=index_std->next;
				continue;
			}
		}
		last_std=index_std;
	}
	if(fde_cs->head==fde_cs->bottom->next){
		fde_cs->head=NULL;
	}
	return fde_cs;
}
void pcr_list(c_std pcr_std){
	int num1,num2;
	p_std index_std;
	scanf("%d",&num1);
	scanf("%d",&num2);
	for(index_std=pcr_std->head;index_std!=pcr_std->bottom->next;index_std=index_std->next){
		if((index_std->number)>=num1&&(index_std->number)<=num2){
			printf("%s %d\n",&index_std->name,index_std->number);
		}
	}
}
void pst_list(c_std pst_std){
	int No_of_nodes=0;
	int Max_count=0;
	int Min_count=99999;
	int Sum_count=0;
	float Avg_count=0;
	float s;
	float n;
	p_std index_std;
	for(index_std=pst_std->head;index_std!=pst_std->bottom->next;index_std=index_std->next){
		No_of_nodes+=1;
		if(index_std->number>Max_count){
			Max_count=index_std->number;
		}
		if(index_std->number<Min_count){
			Min_count=index_std->number;
		}
		Sum_count+=index_std->number;
	}
	s=(float)Sum_count;
	n=(float)No_of_nodes;
	printf("%f %f\n",s,n);
	Avg_count=s/n;
	printf("No. of nodes = %d\n",No_of_nodes);
	printf("Max. count = %d\n",Max_count);
	printf("Min.coun = %d\n",Min_count);
	printf("Avg.count = %f\n",Avg_count);

}

c_std switchfunc(c_std switch_cs){
	char str[4];
	scanf("%s",str);
	if(strcmp(str,"ins")==0){
		switch_cs=ins_list(switch_cs);
	}else if(strcmp(str,"prl")==0){
		prl_list(switch_cs);
	
	}else if(strcmp(str,"end")==0){
		end_list();
	}else if(strcmp(str,"del")==0){
		switch_cs=del_list(switch_cs);
	}else if(strcmp(str,"fde")==0){
		switch_cs=fde_list(switch_cs);
	}else if(strcmp(str,"pcr")==0){
		pcr_list(switch_cs);
	}else if(strcmp(str,"pst")==0){
		pst_list(switch_cs);
	}
	return switch_cs;
}

void main(){
	c_std opera_cs;
	opera_cs=(c_std)malloc(sizeof(struct control_std));
	opera_cs->head=NULL;
	opera_cs->bottom=NULL;
	while(1){
		printf("Command? ");
		opera_cs=switchfunc(opera_cs);
	}
}
