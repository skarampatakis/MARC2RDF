#include <iostream>
#include <fstream>
#include <ios>
#include <sstream>
#include <string>
#include <cmath>
#include <ctime>
#include <sys/stat.h>
#include <sys/types.h>
#include <utility>
using namespace std;

struct tags {
	string a[10];
	int an;
	string b[50];
	int bn;
	string c[10];
	int cn;
	string d[10];
	int dn;
	string e[10];
	int en;
	string f[10];
	int fn;
	string g[10];
	int gn;
	string h[10];
	int hn;
	string i[10];
	int in;
	string j[10];
	int jn;
	string k[10];
	int kn;
	string l[10];
	int ln;
	string m[10];
	int mn;
	string n[10];
	int nn;
	string q[10];
	int qn;
	string s[10];
	int sn;
	string t[10];
	int tn;
	string u[10];
	int un;
	string x[10];
	int xn;
	string y[10];
	int yn;
	string z[10];
	int zn;
	string v[10];
	int vn;
	string nosub;
	int count;
};


struct marc_field {
	string tag;
	int start;
	int length;
	char ind1;
	char ind2;
	string data;
	tags subfield;
	int subfn;
	bool proccessed;
};

struct record {
	marc_field field[1000]; //ta pedia ths eggrafhs
	string leader; // h etiketa eggrafhs
	string directory; // to evrethrio
	string field_container; //ta paidia dedomenwn
	int no_fields; //synolikos arithmos pediwn
	string type; //typos eggrafhs opws exagetai apo to leader[7] h to 200 $b
	int recordID; // id ths eggrafhs, sthn ousia h timh tou 001
};


tags Subfields(marc_field field){
	tags sub ={};
	int sub_pos1 = field.data.find('\037');
	if (sub_pos1==-1){
		sub.nosub=field.data;
		sub.count=0;
	}
	else{
		int sub_pos2;
		do {
			sub_pos2 = field.data.find('\037',sub_pos1+1);
			if (sub_pos2==-1){
				if(field.data[sub_pos1+1]=='a'){
					sub.a[sub.an] = field.data.substr(sub_pos1+2);
					sub.an++;
					sub.count++;
				}
				else if(field.data[sub_pos1+1]=='b'){
					sub.b[sub.bn] = field.data.substr(sub_pos1+2);
					sub.bn++;
					sub.count++;
				}
				else if(field.data[sub_pos1+1]=='c'){
					sub.c[sub.cn] = field.data.substr(sub_pos1+2);
					sub.cn++;
					sub.count++;
				}
				else if(field.data[sub_pos1+1]=='d'){
					sub.d[sub.dn] = field.data.substr(sub_pos1+2);
					sub.dn++;
					sub.count++;
				}
				else if(field.data[sub_pos1+1]=='e'){
					sub.e[sub.en] = field.data.substr(sub_pos1+2);
					sub.en++;
					sub.count++;
				}
				else if(field.data[sub_pos1+1]=='f'){
					sub.f[sub.fn] = field.data.substr(sub_pos1+2);
					sub.fn++;
					sub.count++;
				}
				else if(field.data[sub_pos1+1]=='g'){
					sub.g[sub.gn] = field.data.substr(sub_pos1+2);
					sub.gn++;
					sub.count++;
				}
				else if(field.data[sub_pos1+1]=='h'){
					sub.h[sub.hn] = field.data.substr(sub_pos1+2);
					sub.hn++;
					sub.count++;
				}
				else if(field.data[sub_pos1+1]=='i'){
					sub.i[sub.in] = field.data.substr(sub_pos1+2);
					sub.in++;
					sub.count++;
				}
				else if(field.data[sub_pos1+1]=='j'){
					sub.j[sub.jn] = field.data.substr(sub_pos1+2);
					sub.jn++;
					sub.count++;
				}
				else if(field.data[sub_pos1+1]=='k'){
					sub.k[sub.kn] = field.data.substr(sub_pos1+2);
					sub.kn++;
					sub.count++;
				}
				else if(field.data[sub_pos1+1]=='l'){
					sub.l[sub.ln] = field.data.substr(sub_pos1+2);
					sub.cn++;
					sub.count++;
				}
				else if(field.data[sub_pos1+1]=='m'){
					sub.m[sub.mn] = field.data.substr(sub_pos1+2);
					sub.mn++;
					sub.count++;
				}else if(field.data[sub_pos1+1]=='n'){
					sub.n[sub.nn] = field.data.substr(sub_pos1+2);
					sub.nn++;
					sub.count++;
				}
				else if(field.data[sub_pos1+1]=='q'){
					sub.q[sub.qn] = field.data.substr(sub_pos1+2);
					sub.qn++;
					sub.count++;
				}
				else if(field.data[sub_pos1+1]=='s'){
					sub.s[sub.sn] = field.data.substr(sub_pos1+2);
					sub.sn++;
					sub.count++;
				}else if(field.data[sub_pos1+1]=='t'){
					sub.t[sub.tn] = field.data.substr(sub_pos1+2);
					sub.tn++;
					sub.count++;
				}else if(field.data[sub_pos1+1]=='u'){
					sub.u[sub.un] = field.data.substr(sub_pos1+2);
					sub.un++;
					sub.count++;
				}
				else if(field.data[sub_pos1+1]=='x'){
					sub.x[sub.xn] = field.data.substr(sub_pos1+2);
					sub.xn++;
					sub.count++;
				}
				else if(field.data[sub_pos1+1]=='y'){
					sub.y[sub.yn] = field.data.substr(sub_pos1+2);
					sub.yn++;
					sub.count++;
				}else if(field.data[sub_pos1+1]=='z'){
					sub.z[sub.zn] = field.data.substr(sub_pos1+2);
					sub.zn++;
					sub.count++;
				}else if(field.data[sub_pos1+1]=='v'){
					sub.v[sub.vn] = field.data.substr(sub_pos1+2);
					sub.vn++;
					sub.count++;
				}
			}
			else{
				if(field.data[sub_pos1+1]=='a'){
					sub.a[sub.an] = field.data.substr(sub_pos1+2,sub_pos2-sub_pos1-2);
					sub.an++;
					sub.count++;
				}
				else if(field.data[sub_pos1+1]=='b'){
					sub.b[sub.bn] = field.data.substr(sub_pos1+2,sub_pos2-sub_pos1-2);
					sub.bn++;
					sub.count++;
				}
				else if(field.data[sub_pos1+1]=='c'){
					sub.c[sub.cn] = field.data.substr(sub_pos1+2,sub_pos2-sub_pos1-2);
					sub.cn++;
					sub.count++;
				}
				else if(field.data[sub_pos1+1]=='d'){
					sub.d[sub.dn] = field.data.substr(sub_pos1+2,sub_pos2-sub_pos1-2);
					sub.dn++;
					sub.count++;
				}
				else if(field.data[sub_pos1+1]=='e'){
					sub.e[sub.en] = field.data.substr(sub_pos1+2,sub_pos2-sub_pos1-2);
					sub.en++;
					sub.count++;
				}
				else if(field.data[sub_pos1+1]=='f'){
					sub.f[sub.fn] = field.data.substr(sub_pos1+2,sub_pos2-sub_pos1-2);
					sub.fn++;
					sub.count++;
				}
				else if(field.data[sub_pos1+1]=='g'){
					sub.g[sub.gn] = field.data.substr(sub_pos1+2,sub_pos2-sub_pos1-2);
					sub.gn++;
					sub.count++;
				}
				else if(field.data[sub_pos1+1]=='h'){
					sub.h[sub.hn] = field.data.substr(sub_pos1+2,sub_pos2-sub_pos1-2);
					sub.hn++;
					sub.count++;
				}
				else if(field.data[sub_pos1+1]=='i'){
					sub.i[sub.in] = field.data.substr(sub_pos1+2,sub_pos2-sub_pos1-2);
					sub.in++;
					sub.count++;
				}
				else if(field.data[sub_pos1+1]=='j'){
					sub.j[sub.jn] = field.data.substr(sub_pos1+2,sub_pos2-sub_pos1-2);
					sub.jn++;
					sub.count++;
				}
				else if(field.data[sub_pos1+1]=='k'){
					sub.k[sub.kn] = field.data.substr(sub_pos1+2,sub_pos2-sub_pos1-2);
					sub.kn++;
					sub.count++;
				}
				else if(field.data[sub_pos1+1]=='l'){
					sub.l[sub.ln] = field.data.substr(sub_pos1+2,sub_pos2-sub_pos1-2);
					sub.cn++;
					sub.count++;
				}
				else if(field.data[sub_pos1+1]=='m'){
					sub.m[sub.mn] = field.data.substr(sub_pos1+2,sub_pos2-sub_pos1-2);
					sub.mn++;
					sub.count++;
				}else if(field.data[sub_pos1+1]=='n'){
					sub.n[sub.nn] = field.data.substr(sub_pos1+2,sub_pos2-sub_pos1-2);
					sub.nn++;
					sub.count++;
				}
				else if(field.data[sub_pos1+1]=='q'){
					sub.q[sub.qn] = field.data.substr(sub_pos1+2,sub_pos2-sub_pos1-2);
					sub.qn++;
					sub.count++;
				}
				else if(field.data[sub_pos1+1]=='s'){
					sub.s[sub.sn] = field.data.substr(sub_pos1+2,sub_pos2-sub_pos1-2);
					sub.sn++;
					sub.count++;
				}else if(field.data[sub_pos1+1]=='t'){
					sub.t[sub.tn] = field.data.substr(sub_pos1+2,sub_pos2-sub_pos1-2);
					sub.tn++;
					sub.count++;
				}else if(field.data[sub_pos1+1]=='u'){
					sub.u[sub.un] = field.data.substr(sub_pos1+2,sub_pos2-sub_pos1-2);
					sub.un++;
					sub.count++;
				}
				else if(field.data[sub_pos1+1]=='x'){
					sub.x[sub.xn] = field.data.substr(sub_pos1+2,sub_pos2-sub_pos1-2);
					sub.xn++;
					sub.count++;
				}
				else if(field.data[sub_pos1+1]=='y'){
					sub.y[sub.yn] = field.data.substr(sub_pos1+2,sub_pos2-sub_pos1-2);
					sub.yn++;
					sub.count++;
				}else if(field.data[sub_pos1+1]=='z'){
					sub.z[sub.zn] = field.data.substr(sub_pos1+2,sub_pos2-sub_pos1-2);
					sub.zn++;
					sub.count++;

				}else if(field.data[sub_pos1+1]=='v'){
					sub.v[sub.vn] = field.data.substr(sub_pos1+2,sub_pos2-sub_pos1-2);
					sub.vn++;
					sub.count++;
				}
			}
			sub_pos1=sub_pos2;
		}
		while(sub_pos2!=-1);
	}
	return sub;
}


int FieldFind(record myRecord,string tag){
//this function returns the position of a specific tag with a specific subfield
	int max_records = myRecord.no_fields;
	int i;
	int found=0;
	for (i=0;i<max_records;i++){
		if(myRecord.field[i].tag==tag){
			found=1;
			break;
		}
	}
	if(found==1){
		return i;
	}
	else{
		return -1;
		}
}


string ClassSelector(record myRecord){
	string result,selector;
	selector = myRecord.leader[9];
	if(selector.compare("a")==0){
		result="gnd:Person";
	}
	else if(selector.compare("b")==0){
		int temp = FieldFind(myRecord,"210");
		if (myRecord.field[temp].ind1=='0'){
			result="gnd:CorporateBody";
		}
		else if (myRecord.field[temp].ind1=='1'){
			result="gnd:ConferenceOrEvent";
		}
	}
	else if(selector.compare("c")==0){
		result="gnd:PlaceOrGeographicName";
	}
	else if(selector.compare("d")==0){
		result="gnd:ProductNameOrBrandName";
	}
	else if(selector.compare("e")==0){
		result="gnd:Family";
	}
	else if(selector.compare("f")==0){
		result="gnd:Work";
	}
	else if(selector.compare("j")==0){
		result="gnd:SubjectHeading";
	}
	else{
		result="";
	}
	return result;
}

string ClassFinder(string value, string clas[][2],int max_clas){
//this function finds the Class of the object that the record describes,the velue is the string of the field 200 $b,clas is the array with the classes
//and max_clas is the number of the classes
	int i;
	string found;
	if(found.compare("default")==0){
			found=clas[0][1];
	}
	if(found.compare("book")==0){
			found=clas[0][2];
	}
	for (i=0;i<max_clas;i++){
		if (value.compare(clas[i][0])==0){
			found=clas[i][1];
			break;
		}
	}

	return found;
}

string ClassSelector2(record myRecord,string clas[][2], int max_clas){
	string result,selector;
	//is it a book???check the 010 for isbn
	int temp,temp2;
	temp =FieldFind(myRecord,"010");
	if (temp>0){
		result = ClassFinder("book",clas, max_clas);
	}
	else {
		temp2 = FieldFind(myRecord,"200");
		if((temp2>0) && (myRecord.field[temp2].subfield.bn!=0)){
			result = ClassFinder(myRecord.field[temp2].subfield.b[0],clas,max_clas);
		}
		else {
			result = ClassFinder("default",clas, max_clas);
		}
	}
	return result;
}


int strtoi(string strnumber) {
	int num_length = strnumber.length();
	int sum=0;
	for (int i=0;i<num_length;i++){
		int digit = strnumber[i] - '0';
		sum=sum+(digit*pow(double(10),num_length-i-1));
	}
	return sum;
}


record RecordExtractor (string line,int recordID,string clas[][2],int max_clas){
	record myRecord;
	myRecord.recordID = recordID;
	myRecord.leader = line.substr(0,23); //get leader
	int directory_end = line.find('\36');
	myRecord.directory = line.substr(24,directory_end-24); //get directory
	myRecord.field_container = line.substr(directory_end); //get field container
	myRecord.no_fields = myRecord.directory.length()/12;
	int start=0;
	for (int i=0;i<myRecord.no_fields;i++){
		myRecord.field[i].tag = myRecord.directory.substr(start,3);
		myRecord.field[i].length = strtoi(myRecord.directory.substr(start+3,4));
		myRecord.field[i].start = strtoi(myRecord.directory.substr(start+7,5));
		myRecord.field[i].data = myRecord.field_container.substr(myRecord.field[i].start,myRecord.field[i].length);
		myRecord.field[i].proccessed = false;
		if(strtoi(myRecord.field[i].tag)>9){
			myRecord.field[i].ind1 = myRecord.field[i].data[1]; //get the first indicator
			myRecord.field[i].ind2 = myRecord.field[i].data[2]; //get the second indicator
			myRecord.field[i].data = myRecord.field_container.substr(myRecord.field[i].start+3,myRecord.field[i].length-3);
			tags mySub = Subfields(myRecord.field[i]);
			myRecord.field[i].subfield = mySub;
			myRecord.field[i].subfn = mySub.count;
		}
		else{
			myRecord.field[i].ind1 = 32; //fill with empty character for 0xx tags
			myRecord.field[i].ind2 = 32;
			myRecord.field[i].data = myRecord.field_container.substr(myRecord.field[i].start+1,myRecord.field[i].length-1);
			myRecord.field[i].subfield.nosub = myRecord.field[i].data;
			myRecord.field[i].subfield.count = 1;
			myRecord.field[i].subfn = 1;
		}

		start=start+12; //go to next field
		//end of data reading
	}
	myRecord.type = ClassSelector2(myRecord,clas,max_clas);
	return myRecord;
}

int FieldFind(string fields[][3],string tag, string subfield, int max_records){
//this function returns the position of a specific tag with a specific subfield
	int i;
	int found=0;
	for (i=0;i<max_records;i++){
		if(fields[i][0]==tag && fields[i][1]==subfield){
			found=1;
			break;
		}
	}
	if(found==1){
		return i;
	}
	else{
		return -1;
		}
}


string CleanLiteral(string the_string){
	char bad[] = {'[',']','"'};
	string::size_type n = 0;

	n = 0;
	while ((n=the_string.find(bad[0], n))!=the_string.npos){
		the_string.erase(n,1);
	}
	
	n = 0;
	while ((n=the_string.find(bad[1], n))!=the_string.npos){
		the_string.erase(n,1);
	}
	
	n = 0;
	while ((n=the_string.find(bad[2], n))!=the_string.npos){
		the_string.replace(n,1,"\'");
	}
	return the_string;
}

string StringClean(string the_string){
	char bad[] = {'.', ',', ' ','/'};
	string::size_type n = 0;

	while ((n=the_string.find(bad[0], n))!=the_string.npos){
		the_string.erase(n,1);
	}

	n = 0;
	while ((n=the_string.find(bad[1], n))!=the_string.npos){
		the_string.erase(n,1);
	}

	n = 0;
	while ((n=the_string.find(bad[2], n))!=the_string.npos){
		the_string.erase(n,1);
	}
	
	n = 0;
	while ((n=the_string.find(bad[3], n))!=the_string.npos){
		the_string.replace(n,1,"_");
	}
	return the_string;
}

string StringClean3(string the_string){
	string::size_type n = 0;
	while ((n=the_string.find(' ', n))!=the_string.npos){
		the_string.replace(n,1,"_");
	}
	return the_string;
}

string StringClean2(string the_string){
	char bad[] = {'(', ')', ':'};
	string::size_type n = 0;

	while ((n=the_string.find(bad[0], n))!=the_string.npos){
		the_string.erase(n,1);
	}

	n = 0;
	while ((n=the_string.find(bad[1], n))!=the_string.npos){
		the_string.erase(n,1);
	}

	n = 0;
	while ((n=the_string.find(bad[2], n))!=the_string.npos){
		the_string.erase(n,1);
	}
	return the_string;
}

string Triple(string subject, string property, string object, int literal){
	string triple;
	stringstream ss;
	//flags
	// literal = 0 the triple is object to object
	// literal = 1 the triple is object to string with cleaning proccess
	// literal = 2 the triple is object to string without need for cleaning
	if (literal==0){
		ss<<subject<<'\t'<<property<<'\t'<<object<<" ."<<endl;
	}
	else if (literal==1){
			ss<<subject<<'\t'<<property<<'\t'<<'"'<<CleanLiteral(object)<<'"'<<" ."<<endl;
	}
	else if (literal==2){
			ss<<subject<<'\t'<<property<<'\t'<<"<"<<object<<">"<<" ."<<endl;
	}
	triple=ss.str();
	return triple;
}

string Connector(string prefix,string suffix){
	string connect;
	stringstream ss;
	ss<<prefix<<suffix;
	connect = ss.str();
	return connect;
}

string Connector(string prefix,string suffix, char seperator){
	string connect;
	stringstream ss;
	ss<<prefix<<seperator<<suffix;
	connect = ss.str();
	return connect;
}

void RecordPrint(record myRecord){
	cout<<"--------------------------------------------------"<<endl;
	cout<<"Leader:"<<myRecord.leader<<endl;
	cout<<"Directory:"<<myRecord.directory<<endl;
	cout<<"Number of Fields:"<<myRecord.no_fields<<endl;
	cout<<"Field Tag"<<'\t'<<"ind1"<<'\t'<<"ind2"<<'\t'<<"data"<<endl;
	for(int i=0; i<myRecord.no_fields; i++){
		cout<<myRecord.field[i].tag<<'\t'<<myRecord.field[i].ind1<<'\t'<<myRecord.field[i].ind2<<'\t'<<myRecord.field[i].data<<endl;
	}

}

string dateExtractor(string myDate, string mySubject, int type){
	int check;
	stringstream ss;
	string birth = "";
	string death = "";
	if(myDate[0] == '('){
		check = 1;
	}
	else{
		check=2;
	}
	int temp = myDate.find('-');
	if (temp!=-1){
		if (check == 1){
			birth = myDate.substr(1,temp-1);
			death = myDate.substr(temp+1,myDate.length()-temp-1);
		}
		else if (check == 2){
			birth = myDate.substr(0,temp);
			death = myDate.substr(temp+1,myDate.length()-temp-1);
		}
	}
	else{
		if (check == 1){
			birth = myDate.substr(1,myDate.length()-1);
		}
		else if(check ==2){
			birth = myDate;
		}
	}
	ss<<Triple(mySubject,"gnd:associatedDate",myDate,1);
	if (type == 1){
		ss<<Triple(mySubject,"gnd:dateOfBirth",birth,1);
		if (temp!=-1 && death.length()>2){
			ss<<Triple(mySubject,"gnd:dateOfDeath",death,1);
		}
	}
	string rdf;
	rdf = ss.str();
	return rdf;
}

string NameConnector (marc_field myField){
	string the_string,needle;
	the_string=myField.data;
	string::size_type n = 0;

	while((n=the_string.find('\037', n))!=the_string.npos) {
		if ((needle=the_string[n+1]).compare("b")==0){
			the_string.replace(n,1,",");
			the_string.erase(n+1,1);
		}
		else if ((needle=the_string[n+1]).compare("9")==0){
			the_string.replace(n,1," ");
			the_string.erase(n+1,2);
		}
		else {
			if ((needle=the_string[n+1]).compare("a")!=0){
				the_string.replace(n,1," ");
				the_string.erase(n+1,1);
			}
			else{
				the_string.erase(n,2);
			}
		}

	}
	if(the_string[the_string.length()-1]==32){
		the_string.erase(the_string.length()-1,1);
	}

	return the_string;
}

string NameConnector (marc_field myField, int type){
	string the_string,needle;
	the_string=myField.data;
	string::size_type n = 0;

	while((n=the_string.find('\037', n))!=the_string.npos) {
		the_string.replace(n,1,"-");
		the_string.erase(n+1,1);
	}
	if(the_string[the_string.length()-1]==32){
		the_string.erase(the_string.length()-1,1);
	}
	the_string.erase(0,1);
	return the_string;
}

string AgentIRI(string the_string){
	ifstream agents;
	stringstream ss;
	int found,id;
	string name,iri;
	the_string = StringClean3(the_string);
	agents.open("id/agents.txt");
	id=1;
	if (agents.is_open()) {
		while(!agents.eof()){
			agents>>id>>name>>iri;
			if (name.compare(the_string)==0){
				agents.close();
				return iri;
				}
			id++;
			}
		}
	ss<<"agent"<<id;
	iri=ss.str();
	agents.close();
	ofstream agents2;
	agents2.open("id/agents.txt",ios::app);
	agents2<<id<<'\t'<<the_string<<'\t'<<iri<<endl;
	agents2.close();
	return iri;
}

string PlaceOfPublicationIRI(string the_string){
	ifstream agents;
	stringstream ss;
	int found,id;
	string name,iri;
	agents.open("id/places.txt");
	id=1;
	the_string = StringClean3(the_string);
	if (agents.is_open()) {
		while(!agents.eof()){
			agents>>id>>name>>iri;
			if (name.compare(the_string)==0){
				agents.close();
				return iri;
			}
			id++;
		}
	}
	ss<<"place"<<id;
	iri=ss.str();
	agents.close();
	ofstream agents2;
	agents2.open("id/places.txt",ios::app);
	agents2<<id<<'\t'<<the_string<<'\t'<<iri<<endl;
	agents2.close();
	return iri;
}

string PublisherIRI(string the_string){
	ifstream agents;
	stringstream ss;
	int found,id;
	string name,iri;
	agents.open("id/publishers.txt");
	id=1;
	the_string = StringClean3(the_string);
	if (agents.is_open()) {
		while(!agents.eof()){
			agents>>id>>name>>iri;
			if (name.compare(the_string)==0){
				agents.close();
				return iri;
				}
			id++;

		}
	}
	ss<<"publisher"<<id;
	iri=ss.str();
	agents.close();
	ofstream agents2;
	agents2.open("id/publishers.txt",ios::app);
	agents2<<id<<'\t'<<the_string<<'\t'<<iri<<endl;
	agents2.close();
	return iri;
}
string SeriesIRI(string the_string){
	ifstream agents;
	stringstream ss;
	int found,id;
	string name,iri;
	agents.open("id/series.txt");
	id=1;
	the_string = StringClean3(the_string);
	if (agents.is_open()) {
		while(!agents.eof()){
			agents>>id>>name>>iri;
			if (name.compare(the_string)==0){
				agents.close();
				return iri;
				}
			id++;

		}
	}
	ss<<"serie"<<id;
	iri=ss.str();
	agents.close();
	ofstream agents2;
	agents2.open("id/series.txt",ios::app);
	agents2<<id<<'\t'<<the_string<<'\t'<<iri<<endl;
	agents2.close();
	return iri;
}

int NumOfValues(string field,char seperator){
	//this function takes a field and returns the number of individual values inside the field seperated by the seperator
	int temp=field.find(seperator);
	int k=1;
	while(temp!=-1){
		k++;
		temp=field.find(seperator,temp+1);
		}
	return k;
	}

string FieldRank(string field, int rank, char seperator){
	//this function returns the ith value of the field ie. if a field contains 5 values seperated by commas and you want the 3rd value use string = AuthorRank(field,3)
	int temp=field.find(seperator);
	int pos[100];
	string value;
	int k=1;
	pos[0]=0;
	pos[1]=temp+1;
	while(temp!=-1){
		k++;
		temp=field.find(seperator,temp+2);
		pos[k]=temp+1;
		}
	pos[k]=field.length();
	value=field.substr(pos[rank-1],pos[rank]-pos[rank-1]);
	int it;
	if (value[0]==' '){
		value.erase(0,1);
		}
	it=value.length();
	if (value[it-1]==','){
		value.erase(it-1,1);
		}
	return value;
}

string SubjectIRI(string the_string){
	ifstream agents;
	stringstream ss;
	int found,id;
	string name,iri;
	agents.open("id/subjects.txt");
	the_string = StringClean3(the_string);
	id=1;
	if (agents.is_open()) {
		while(!agents.eof()){
			agents>>id>>name>>iri;
			if (name.compare(the_string)==0){
				agents.close();
				return iri;
				}
			id++;
			}
		}
	ss<<"subject"<<id;
	iri=ss.str();
	agents.close();
	ofstream agents2;
	agents2.open("id/subjects.txt",ios::app);
	agents2<<id<<'\t'<<the_string<<'\t'<<iri<<endl;
	agents2.close();
	return iri;
}

string LibraryIRI(string the_string){
	ifstream agents;
	stringstream ss;
	int found,id;
	string name,iri;
	agents.open("id/libraries.txt");
	id=1;
	the_string = StringClean3(the_string);
	if (agents.is_open()) {
		while(!agents.eof()){
			agents>>id>>name>>iri;
			if (name.compare(the_string)==0){
				agents.close();
				return iri;
				}
			id++;
			}
		}
	ss<<"library"<<id;
	iri=ss.str();
	agents.close();
	ofstream agents2;
	agents2.open("id/libraries.txt",ios::app);
	agents2<<id<<'\t'<<the_string<<'\t'<<iri<<endl;
	agents2.close();
	return iri;
}
string Chainshaw(string the_string, char seperator){
	int found;
	string result;
	found = the_string.find_last_of(seperator);
	result ="";
	if(found!=-1){
		result = the_string.substr(0,found);
	}
	return result;
}
/////////////////////////////////////////////TAGS////////////////////////////////////////////////////////
////////////////////////////////////////GENERIC/////////////////////////////////////////////////////////////

string generic(marc_field myField, string mySubject, string mappings[][3], int max_clas){
	stringstream ss;
	string result;
	int temp,i;

	temp = FieldFind(mappings,myField.tag,"a",max_clas);
	if(temp!=-1){
		for (i=0;i<myField.subfield.an;i++){
			ss<<Triple(mySubject,mappings[temp][2],myField.subfield.a[i],1);
		}
	}
	temp = FieldFind(mappings,myField.tag,"b",max_clas);
	if(temp!=-1){
		for (i=0;i<myField.subfield.bn;i++){
			ss<<Triple(mySubject,mappings[temp][2],myField.subfield.b[i],1);
		}
	}
	temp = FieldFind(mappings,myField.tag,"c",max_clas);
	if(temp!=-1){
		for (i=0;i<myField.subfield.cn;i++){
			ss<<Triple(mySubject,mappings[temp][2],myField.subfield.c[i],1);
		}
	}
	temp = FieldFind(mappings,myField.tag,"d",max_clas);
	if(temp!=-1){
		for (i=0;i<myField.subfield.dn;i++){
			ss<<Triple(mySubject,mappings[temp][2],myField.subfield.d[i],1);
		}
	}
	temp = FieldFind(mappings,myField.tag,"e",max_clas);
	if(temp!=-1){
		for (i=0;i<myField.subfield.en;i++){
			ss<<Triple(mySubject,mappings[temp][2],myField.subfield.e[i],1);
		}
	}
	temp = FieldFind(mappings,myField.tag,"f",max_clas);
	if(temp!=-1){
		for (i=0;i<myField.subfield.fn;i++){
			ss<<Triple(mySubject,mappings[temp][2],myField.subfield.f[i],1);
		}
	}
	temp = FieldFind(mappings,myField.tag,"g",max_clas);
	if(temp!=-1){
		for (i=0;i<myField.subfield.gn;i++){
			ss<<Triple(mySubject,mappings[temp][2],myField.subfield.g[i],1);
		}
	}
	temp = FieldFind(mappings,myField.tag,"h",max_clas);
	if(temp!=-1){
		for (i=0;i<myField.subfield.hn;i++){
			ss<<Triple(mySubject,mappings[temp][2],myField.subfield.h[i],1);
		}
	}
	temp = FieldFind(mappings,myField.tag,"i",max_clas);
	if(temp!=-1){
		for (i=0;i<myField.subfield.in;i++){
			ss<<Triple(mySubject,mappings[temp][2],myField.subfield.i[i],1);
		}
	}
	temp = FieldFind(mappings,myField.tag,"j",max_clas);
	if(temp!=-1){
		for (i=0;i<myField.subfield.jn;i++){
			ss<<Triple(mySubject,mappings[temp][2],myField.subfield.j[i],1);
		}
	}
	temp = FieldFind(mappings,myField.tag,"k",max_clas);
	if(temp!=-1){
		for (i=0;i<myField.subfield.kn;i++){
			ss<<Triple(mySubject,mappings[temp][2],myField.subfield.k[i],1);
		}
	}
	temp = FieldFind(mappings,myField.tag,"l",max_clas);
	if(temp!=-1){
		for (i=0;i<myField.subfield.ln;i++){
			ss<<Triple(mySubject,mappings[temp][2],myField.subfield.l[i],1);
		}
	}
	temp = FieldFind(mappings,myField.tag,"m",max_clas);
	if(temp!=-1){
		for (i=0;i<myField.subfield.mn;i++){
			ss<<Triple(mySubject,mappings[temp][2],myField.subfield.m[i],1);
		}
	}
	temp = FieldFind(mappings,myField.tag,"n",max_clas);
	if(temp!=-1){
		for (i=0;i<myField.subfield.nn;i++){
			ss<<Triple(mySubject,mappings[temp][2],myField.subfield.n[i],1);
		}
	}
	temp = FieldFind(mappings,myField.tag,"q",max_clas);
	if(temp!=-1){
		for (i=0;i<myField.subfield.qn;i++){
			ss<<Triple(mySubject,mappings[temp][2],myField.subfield.q[i],1);
		}
	}
	temp = FieldFind(mappings,myField.tag,"s",max_clas);
	if(temp!=-1){
		for (i=0;i<myField.subfield.sn;i++){
			ss<<Triple(mySubject,mappings[temp][2],myField.subfield.s[i],1);
		}
	}
	temp = FieldFind(mappings,myField.tag,"t",max_clas);
	if(temp!=-1){
		for (i=0;i<myField.subfield.tn;i++){
			ss<<Triple(mySubject,mappings[temp][2],myField.subfield.t[i],1);
		}
	}
	temp = FieldFind(mappings,myField.tag,"u",max_clas);
	if(temp!=-1){
		for (i=0;i<myField.subfield.un;i++){
			ss<<Triple(mySubject,mappings[temp][2],myField.subfield.u[i],1);
		}
	}
	temp = FieldFind(mappings,myField.tag,"x",max_clas);
	if(temp!=-1){
		for (i=0;i<myField.subfield.xn;i++){
			ss<<Triple(mySubject,mappings[temp][2],myField.subfield.x[i],1);
		}
	}
	temp = FieldFind(mappings,myField.tag,"y",max_clas);
	if(temp!=-1){
		for (i=0;i<myField.subfield.yn;i++){
			ss<<Triple(mySubject,mappings[temp][2],myField.subfield.y[i],1);
		}
	}
	temp = FieldFind(mappings,myField.tag,"z",max_clas);
	if(temp!=-1){
		for (i=0;i<myField.subfield.zn;i++){
			ss<<Triple(mySubject,mappings[temp][2],myField.subfield.z[i],1);
		}
	}
	temp = FieldFind(mappings,myField.tag,"v",max_clas);
	if(temp!=-1){
		for (i=0;i<myField.subfield.vn;i++){
			ss<<Triple(mySubject,mappings[temp][2],myField.subfield.v[i],1);
		}
	}
	temp = FieldFind(mappings,myField.tag,"00",max_clas);
	if(temp!=-1){
		for (i=0;i<myField.subfield.count;i++){
			ss<<Triple(mySubject,mappings[temp][2],myField.subfield.nosub,1);
		}
	}
	result = ss.str();
	return result;
}
///////////////////////////////////////////1-BLOCK/////////////////////////////////////////////////////////


string tag100(string myString, string mySubject){
	string myDate;
	stringstream ss,date;
	myDate = myString.substr(0,8);
	date<<'"'<<myDate.substr(0,4)<<"-"<<myDate.substr(4,2)<<"-"<<myDate.substr(6,2)<<'"'<<"^^xsd:date";
	ss<<Triple(mySubject,"dcterms:created",date.str(),0);
	string result;
	result = ss.str();
	return result;
}
////////////////////////////////////////////2-- BLOCK////////////////////////////////////////////////////
string tag200(marc_field myField, string mySubject, string mappings[][3], int max_clas){
	stringstream ss;
	string result;
	int temp,i;

	temp = FieldFind(mappings,"200","a",max_clas);
	if(temp!=-1){
		for (i=0;i<myField.subfield.an;i++){
			ss<<Triple(mySubject,mappings[temp][2],myField.subfield.a[i],1);
		}
	}
	temp = FieldFind(mappings,"200","b",max_clas);
	if(temp!=-1){
		for (i=0;i<myField.subfield.bn;i++){
			ss<<Triple(mySubject,mappings[temp][2],myField.subfield.b[i],1);
		}
	}
	temp = FieldFind(mappings,"200","e",max_clas);
	if(temp!=-1){
		for (i=0;i<myField.subfield.en;i++){
			ss<<Triple(mySubject,mappings[temp][2],myField.subfield.e[i],1);
		}
	}
	temp = FieldFind(mappings,"200","d",max_clas);
	if(temp!=-1){
		for (i=0;i<myField.subfield.dn;i++){
			ss<<Triple(mySubject,mappings[temp][2],myField.subfield.d[i],1);
		}
	}
	temp = FieldFind(mappings,"200","g",max_clas);
	if(temp!=-1){
		for (i=0;i<myField.subfield.gn;i++){
			ss<<Triple(mySubject,mappings[temp][2],myField.subfield.g[i],1);
		}
	}
	temp = FieldFind(mappings,"200","f",max_clas);
	if(temp!=-1){
		for (i=0;i<myField.subfield.fn;i++){
			ss<<Triple(mySubject,mappings[temp][2],myField.subfield.f[i],1);
		}
	}
	ss<<Triple(mySubject,"rdfs:label",NameConnector(myField,1),1);
	result = ss.str();
	return result;
}

string tag210(marc_field myField, string mySubject, string mappings[][3], int max_clas){
	stringstream ss,place,publisher,date;
	string result,myPlace,myPublisher,myDate;
	int temp,i;

	temp = FieldFind(mappings,"210","a",max_clas);
	if(temp!=-1){
		for (i=0;i<myField.subfield.an;i++){
			place<<"library:"<<PlaceOfPublicationIRI(myField.subfield.a[i]);
			myPlace=place.str();
			ss<<Triple(myPlace,"rdf:type","schema:Place",0);
			ss<<Triple(myPlace,"rdfs:label",myField.subfield.a[i],1);
			ss<<Triple(mySubject,mappings[temp][2],myPlace,0);

		}
	}
	temp = FieldFind(mappings,"210","c",max_clas);
	if(temp!=-1){
		for (i=0;i<myField.subfield.cn;i++){
			publisher<<"library:"<<PublisherIRI(myField.subfield.c[i]);
			myPublisher=publisher.str();
			ss<<Triple(myPublisher,"rdf:type","foaf:Organization",0);
			ss<<Triple(myPublisher,"rdfs:label",myField.subfield.c[i],1);
			ss<<Triple(mySubject,mappings[temp][2],publisher.str(),0);
		}
	}
	temp = FieldFind(mappings,"210","d",max_clas);
	if(temp!=-1){
		for (i=0;i<myField.subfield.dn;i++){
			date<<'"'<<myField.subfield.d[i]<<'"'<<"^^xsd:gYear";
			ss<<Triple(mySubject,mappings[temp][2],date.str(),0);
		}
	}
	result = ss.str();
	return result;
}


string tag215(marc_field myField, string mySubject, string mappings[][3], int max_clas){
	stringstream ss;
	string result;
	int temp,i;

	temp = FieldFind(mappings,"215","a",max_clas);
	if(temp!=-1){
		for (i=0;i<myField.subfield.an;i++){
			ss<<Triple(mySubject,mappings[temp][2],myField.subfield.a[i],1);
		}
	}
	temp = FieldFind(mappings,"215","c",max_clas);
	if(temp!=-1){
		for (i=0;i<myField.subfield.cn;i++){
			ss<<Triple(mySubject,mappings[temp][2],myField.subfield.c[i],1);
		}
	}
	temp = FieldFind(mappings,"215","d",max_clas);
	if(temp!=-1){
		for (i=0;i<myField.subfield.dn;i++){
			ss<<Triple(mySubject,mappings[temp][2],myField.subfield.d[i],1);
		}
	}
	temp = FieldFind(mappings,"215","e",max_clas);
		if(temp!=-1){
			for (i=0;i<myField.subfield.en;i++){
				ss<<Triple(mySubject,mappings[temp][2],myField.subfield.e[i],1);
		}
	}

	result = ss.str();
	return result;
}


string tag225(marc_field myField, string mySubject, string mappings[][3], int max_clas){
	stringstream ss,serie;
	string result,mySeries;
	int temp,i;

	temp = FieldFind(mappings,"225","a",max_clas);
	if(temp!=-1){
		for (i=0;i<myField.subfield.an;i++){
			serie<<"library:"<<SeriesIRI(myField.subfield.a[i]);
			mySeries=serie.str();
			ss<<Triple(mySeries,"rdf:type","bibo:Serie",0);
			ss<<Triple(mySeries,"rdfs:label",myField.subfield.a[i],1);
			ss<<Triple(mySubject,mappings[temp][2],mySeries,0);

		}
	}
	temp = FieldFind(mappings,"225","v",max_clas);
	if(temp!=-1){
		for (i=0;i<myField.subfield.vn;i++){
			ss<<Triple(mySubject,mappings[temp][2],myField.subfield.v[i],1);
		}
	}
	temp = FieldFind(mappings,"225","e",max_clas);
	if(temp!=-1){
		for (i=0;i<myField.subfield.en;i++){
			ss<<Triple(mySubject,mappings[temp][2],myField.subfield.e[i],1);
		}
	}
	temp = FieldFind(mappings,"225","h",max_clas);
	if(temp!=-1){
		for (i=0;i<myField.subfield.hn;i++){
			ss<<Triple(mySubject,mappings[temp][2],myField.subfield.h[i],1);
		}
	}

	result = ss.str();
	return result;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////3-- BLOCK////////////////////////////////////////////////////
string tag323(marc_field myField, string mySubject, string mappings[][3], int max_clas){
	stringstream ss,performer;
	string result,myPerformer,tempPerformer,temp3,temp4;
	int temp,temp2,temp5,i;
	temp2 = NumOfValues(myField.subfield.a[0],',');
	temp = myField.subfield.a[0].find(':');
	if (temp!=-1){
		temp3 = myField.subfield.a[0].erase(0,temp+1);
	}
	else {
		temp3= myField.subfield.a[0];
	}
	cout<<temp3;
	temp = FieldFind(mappings,"323","a",max_clas);
	if(temp!=-1){
	for (i=0;i<temp2;i++){
		performer.str("");
		tempPerformer = FieldRank(temp3,i+1,',');
		performer<<"library:"<<AgentIRI(tempPerformer);
		myPerformer = performer.str();
		ss<<Triple(myPerformer,"rdf:type","foaf:Person",0);
		ss<<Triple(myPerformer,"rdfs:label",tempPerformer,1);
		ss<<Triple(myPerformer,"foaf:name",tempPerformer,1);
		temp5 = tempPerformer.find(' ');
		if (temp5==0){
			tempPerformer.erase(0,1);
		}
		temp4 = FieldRank(tempPerformer,1,' ');
		ss<<Triple(myPerformer,"foaf:givenName",temp4.erase(temp4.length()-1,1),1);
		ss<<Triple(myPerformer,"foaf:surname",tempPerformer.erase(0,temp4.length()+1),1);
		ss<<Triple(mySubject,mappings[temp][2],myPerformer,0);
	}
	}
	result = ss.str();
	return result;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////4-- BLOCK////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////SEE ALSO//////////////////////////////////////////////////////

//////////////////////////////////////////////6-- BLOCK////////////////////////////////////////////////////
string tag600(marc_field myField, string mySubject){
	stringstream s1,s2,s3;
	string perfname,prefEntity,temp4;
	string firstname = "";
	string lastname = "";
	string rdf;
	firstname = myField.subfield.b[0];
	lastname = myField.subfield.a[0];
	s2<<lastname<<" "<<firstname;
	perfname = s2.str();
	s2.str("");
	s2<<"library:"<<SubjectIRI(NameConnector(myField));
	prefEntity = s2.str();

	s1<<Triple(mySubject,"dc:subject",prefEntity,0);
	s1<<Triple(prefEntity,"rdf:type","skos:Concept",0);
	s1<<Triple(prefEntity,"skos:prefLabel",NameConnector(myField),1);
	s1<<Triple(prefEntity,"rdfs:label",NameConnector(myField),1);
	for (int i=0;i<myField.subfield.xn;i++){
			s1<<Triple(prefEntity,"gnd:broaderTermGeneral",myField.subfield.x[i],1);
	}
	for (int i=0;i<myField.subfield.yn;i++){
		s1<<Triple(prefEntity,"gnd:place",myField.subfield.y[i],1);
	}
	for (int i=0;i<myField.subfield.zn;i++){
		s1<<Triple(prefEntity,"gnd:associatedDate",StringClean2(myField.subfield.z[i]),1);
	}

	if(myField.subfield.cn!=0 && myField.subfield.fn!=0){
		s3<<perfname<<" "<<myField.subfield.c[0]<<" "<<myField.subfield.f[0];
	}
	else if(myField.subfield.cn==0 && myField.subfield.fn!=0){
		s3<<perfname<<" "<<myField.subfield.f[0];
	}
	else if(myField.subfield.cn!=0 && myField.subfield.fn==0){
		s3<<perfname<<" "<<myField.subfield.c[0];
	}
	else{
		s3<<perfname;
	}
	temp4 = prefEntity;
	prefEntity = s3.str();
	s3.str("");
	s3<<"library:"<<AgentIRI(prefEntity);
	prefEntity = s3.str();
	s1<<Triple(temp4,"rdfs:seeAlso",prefEntity,0);
	s1<<Triple(prefEntity,"rdf:type","foaf:Person",0);
	s1<<Triple(prefEntity,"rdfs:label",perfname,1);
	s1<<Triple(prefEntity,"foaf:name",perfname,1);
	if(myField.subfield.bn!=0){
		s1<<Triple(prefEntity,"foaf:givenName",firstname,1);
	}
	s1<<Triple(prefEntity,"foaf:surname",lastname,1);
	for (int i=0;i<myField.subfield.cn;i++){
		s1<<Triple(prefEntity,"foaf:title",StringClean2(myField.subfield.c[i]),1);
	}
	if (myField.subfield.fn!=0){
		s1<<dateExtractor(StringClean2(myField.subfield.f[0]),prefEntity,1);
	}

	rdf = s1.str();

	return rdf;
}

string tag601(marc_field myField, string mySubject){
	stringstream s1,s2,s3;
	string perfname,prefEntity,temp4;
	string firstname = "";
	string lastname = "";
	string rdf;
	firstname = myField.subfield.b[0];
	lastname = myField.subfield.a[0];
	s2<<lastname<<" "<<firstname;
	perfname = s2.str();
	s2.str("");
	s2<<"library:"<<SubjectIRI(NameConnector(myField));
	prefEntity = s2.str();

	s1<<Triple(mySubject,"dc:subject",prefEntity,0);
	s1<<Triple(prefEntity,"rdf:type","skos:Concept",0);
	s1<<Triple(prefEntity,"skos:prefLabel",NameConnector(myField),1);
	s1<<Triple(prefEntity,"rdfs:label",NameConnector(myField),1);
	for (int i=0;i<myField.subfield.xn;i++){
			s1<<Triple(prefEntity,"gnd:broaderTermGeneral",myField.subfield.x[i],1);
	}
	for (int i=0;i<myField.subfield.yn;i++){
		s1<<Triple(prefEntity,"gnd:place",myField.subfield.y[i],1);
	}
	for (int i=0;i<myField.subfield.zn;i++){
		s1<<Triple(prefEntity,"gnd:associatedDate",StringClean2(myField.subfield.z[i]),1);
	}

	if(myField.subfield.cn!=0 && myField.subfield.fn!=0){
		s3<<perfname<<" "<<myField.subfield.c[0]<<" "<<myField.subfield.f[0];
	}
	else if(myField.subfield.cn==0 && myField.subfield.fn!=0){
		s3<<perfname<<" "<<myField.subfield.f[0];
	}
	else if(myField.subfield.cn!=0 && myField.subfield.fn==0){
		s3<<perfname<<" "<<myField.subfield.c[0];
	}
	else{
		s3<<perfname;
	}
	temp4 = prefEntity;
	prefEntity = s3.str();
	s3.str("");
	s3<<"library:"<<AgentIRI(prefEntity);
	prefEntity = s3.str();
	s1<<Triple(temp4,"rdfs:seeAlso",prefEntity,0);
	s1<<Triple(prefEntity,"rdf:type","foaf:Organization",0);
	s1<<Triple(prefEntity,"foaf:name",perfname,1);
	rdf = s1.str();

	return rdf;
}


string tag606(marc_field myField, string mySubject, string mappings[][3], int max_clas){
	stringstream ss,subject;
	string mySub,label,mySub2;
	marc_field temp2;
	int temp,count;
	temp2 = myField;
	temp2.subfield = Subfields(temp2);
	label = NameConnector(myField);
	count = 0;
	while(label.length()!=0){
		subject<<"library:"<<SubjectIRI(label);
		mySub = subject.str();
		subject.str("");
		ss<<Triple(mySub,"rdf:type","skos:Concept",0);
		ss<<Triple(mySub,"skos:prefLabel",label,1);
		ss<<Triple(mySub,"rdfs:label",label,1);
		if (count==0){
			ss<<Triple(mySubject,"dc:subject",mySub,0);
		}
		else{
			ss<<Triple(mySub,"skos:narrower",mySub2,0);
		}
		for (int i=0;i<temp2.subfield.xn;i++){
				ss<<Triple(mySub,"gnd:broaderTermGeneral",temp2.subfield.x[i],1);
		}
		for (int i=0;i<temp2.subfield.yn;i++){
			ss<<Triple(mySub,"gnd:place",temp2.subfield.y[i],1);
		}
		for (int i=0;i<temp2.subfield.zn;i++){
			ss<<Triple(mySub,"gnd:associatedDate",StringClean2(temp2.subfield.z[i]),1);
		}
		mySub2=mySub;
		temp2.data = Chainshaw (temp2.data,'\37');
		temp2.subfield = Subfields(temp2);
		label = NameConnector(temp2);
		count++;
	}
	string rdf;
	rdf = ss.str();
	return rdf;
}


string tag607(marc_field myField, string mySubject){
	stringstream s1,s2,s3;
	string perfname,prefEntity,temp4;
	string firstname = "";
	string lastname = "";
	string rdf;
	perfname = myField.subfield.a[0];
	s2.str("");
	s2<<"library:"<<SubjectIRI(NameConnector(myField));
	prefEntity = s2.str();

	s1<<Triple(mySubject,"dc:subject",prefEntity,0);
	s1<<Triple(prefEntity,"rdf:type","skos:Concept",0);
	s1<<Triple(prefEntity,"skos:prefLabel",NameConnector(myField),1);
	s1<<Triple(prefEntity,"rdfs:label",NameConnector(myField),1);
	for (int i=0;i<myField.subfield.xn;i++){
			s1<<Triple(prefEntity,"gnd:broaderTermGeneral",myField.subfield.x[i],1);
	}
	for (int i=0;i<myField.subfield.yn;i++){
		s1<<Triple(prefEntity,"gnd:place",myField.subfield.y[i],1);
	}
	for (int i=0;i<myField.subfield.zn;i++){
		s1<<Triple(prefEntity,"gnd:associatedDate",StringClean2(myField.subfield.z[i]),1);
	}

	if(myField.subfield.an!=0 && myField.subfield.yn!=0){
		s3<<myField.subfield.a[0]<<" "<<myField.subfield.y[0];
	}
	else if(myField.subfield.an!=0 && myField.subfield.yn==0){
		s3<<myField.subfield.a[0];
	}
	temp4 = prefEntity;
	prefEntity = s3.str();
	s3.str("");
	s3<<"library:"<<PlaceOfPublicationIRI(prefEntity);
	prefEntity = s3.str();
	s1<<Triple(temp4,"rdfs:seeAlso",prefEntity,0);
	s1<<Triple(prefEntity,"rdf:type","schema:Place",0);
	s1<<Triple(prefEntity,"rdfs:label",perfname,1);
	rdf = s1.str();

	return rdf;
}

string tag676(marc_field myField, string mySubject){
	string result,dewey;
	stringstream ss,s2;
	int temp;
	dewey = myField.subfield.a[0];
	temp = dewey.find('.');
	if(temp!=-1){
		dewey.replace(temp,1,"_");
	}
	temp = dewey.find(',');
	if(temp!=-1){
		dewey.replace(temp,1,"_");
	}
	temp = dewey.find(' ');
	if(temp!=-1){
		dewey = dewey.substr(0,temp);
	}
	s2<<"library:dewey_"<<StringClean2(dewey);
	dewey = s2.str();
	ss<<Triple(mySubject, "dcterms:DDC", dewey, 0);
	ss<<Triple(dewey, "rdf:type", "owl:Thing",0);
	ss<<Triple(dewey, "rdfs:label", myField.subfield.a[0],1);
	result = ss.str();
	return result;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////7-BLOCK//////////////////////////////////////////////////////
string replace (string myString, string bad_string, string replace_string){
		string result;
	string::size_type n = 0;
	while ((n=myString.find(bad_string, n))!=myString.npos){
			myString.replace(n,1,replace_string);
	}
	return myString;
}



string tag7xx(marc_field myField, string mySubject){
	stringstream s1,s2,s3;
	string perfname,prefEntity,temp4;
	string firstname = "";
	string lastname = "";
	string rdf,temp;
	myField.data = replace(myField.data,",","");
	firstname = myField.subfield.b[0] = replace(myField.subfield.b[0],",","");
	lastname = myField.subfield.a[0] = replace(myField.subfield.a[0],",","");
	s2<<lastname<<" "<<firstname;
	perfname = s2.str();
	s2.str("");
	s2<<"library:"<<AgentIRI(replace(NameConnector(myField),","," "));
	prefEntity = s2.str();

	s1<<Triple(mySubject,"dc:contributor",prefEntity,0);
	s1<<Triple(prefEntity,"rdf:type","foaf:Person",0);
	s1<<Triple(prefEntity,"rdfs:label",NameConnector(myField),1);
	s1<<Triple(prefEntity,"foaf:name",perfname,1);
	if(myField.subfield.bn!=0){
		s1<<Triple(prefEntity,"foaf:givenName",firstname,1);
	}
	s1<<Triple(prefEntity,"foaf:surname",lastname,1);
	for (int i=0;i<myField.subfield.cn;i++){
		s1<<Triple(prefEntity,"foaf:title",StringClean2(myField.subfield.c[i]),1);
	}
	if (myField.subfield.fn!=0){
		s1<<dateExtractor(StringClean2(myField.subfield.f[0]),prefEntity,1);
	}
	rdf = s1.str();
	return rdf;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////8-- BLOCK///////////////////////////////////////////////////////////

string tag801(marc_field myField, string mySubject){
	string result,owner;
	stringstream ss,s2;
	int temp;

	s2<<"library:"<<LibraryIRI(myField.subfield.b[0]);
	owner = s2.str();
	ss<<Triple(mySubject, "dc:creator", owner, 0);
	if(myField.subfield.cn!=0){
		ss<<Triple(mySubject, "dcterms:created", myField.subfield.c[0],1);
	}
	ss<<Triple(owner, "rdf:type", "foaf:Organization",0);
	ss<<Triple(owner, "rdfs:label", myField.subfield.b[0],1);
	result = ss.str();
	return result;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////////////////////////
string RDFtransformer(record myRecord, string mySubject, string mappings[][3], int max_clas){
	stringstream ss;
	string rdf;
	string type = myRecord.type;
	if (type.length()!=0){
		ss<<Triple(mySubject,"rdf:type",type,0);
	}
	else{
		ss<<"[Class Error]:Record number "<<myRecord.recordID<<" does not have a proper class. Record was scraped"<<"\n";
		rdf = ss.str();
		return rdf;
	}
	for (int i=0; i<myRecord.no_fields ; i++){
		if (myRecord.field[i].tag.compare("100")==0){
			ss<<tag100(myRecord.field[i].subfield.a[0],mySubject);
			myRecord.field[i].proccessed = true;
		}
		else if (myRecord.field[i].tag.compare("200")==0){
			ss<<tag200(myRecord.field[i],mySubject, mappings, max_clas);
			myRecord.field[i].proccessed = true;
		}
		else if (myRecord.field[i].tag.compare("210")==0){
			ss<<tag210(myRecord.field[i],mySubject, mappings, max_clas);
			myRecord.field[i].proccessed = true;
		}
		else if (myRecord.field[i].tag.compare("215")==0){
			ss<<tag215(myRecord.field[i],mySubject, mappings, max_clas);
			myRecord.field[i].proccessed = true;
		}
		else if (myRecord.field[i].tag.compare("225")==0){
			ss<<tag215(myRecord.field[i],mySubject, mappings, max_clas);
			myRecord.field[i].proccessed = true;
		}
		else if (myRecord.field[i].tag.compare("323")==0){
			ss<<tag323(myRecord.field[i],mySubject, mappings, max_clas);
			myRecord.field[i].proccessed = true;
		}
		else if (myRecord.field[i].tag.compare("600")==0){
			ss<<tag600(myRecord.field[i],mySubject);
			myRecord.field[i].proccessed = true;
		}
		else if (myRecord.field[i].tag.compare("601")==0){
			ss<<tag601(myRecord.field[i],mySubject);
			myRecord.field[i].proccessed = true;
		}
		else if (myRecord.field[i].tag.compare("606")==0){
			ss<<tag606(myRecord.field[i],mySubject, mappings, max_clas);
			myRecord.field[i].proccessed = true;
		}
		else if (myRecord.field[i].tag.compare("607")==0 && myRecord.field[i].subfield.an!=0){
			ss<<tag607(myRecord.field[i],mySubject);
			myRecord.field[i].proccessed = true;
		}
		else if (myRecord.field[i].tag.compare("676")==0){
			ss<<tag676(myRecord.field[i],mySubject);
			myRecord.field[i].proccessed = true;
		}
		else if (myRecord.field[i].tag.compare("700")==0){
			ss<<tag7xx(myRecord.field[i],mySubject);
			myRecord.field[i].proccessed = true;
		}
		else if (myRecord.field[i].tag.compare("701")==0){
			ss<<tag7xx(myRecord.field[i],mySubject);
			myRecord.field[i].proccessed = true;
		}
		else if (myRecord.field[i].tag.compare("702")==0){
			ss<<tag7xx(myRecord.field[i],mySubject);
			myRecord.field[i].proccessed = true;
		}
		else if (myRecord.field[i].tag.compare("801")==0){
			ss<<tag801(myRecord.field[i],mySubject);
			myRecord.field[i].proccessed = true;
		}
		else{
			ss<<generic(myRecord.field[i],mySubject, mappings, max_clas);
			myRecord.field[i].proccessed = true;
		}
	}
	rdf = ss.str();
	return rdf;
}

int main(int argc,char* argv[]){
	string map[1000][3],prefix[100],tag_index[1000][2];
	tag_index[0][0]="";
	tag_index[0][1]="";
	stringstream ss;
	int z;
	int max_fields,max_clas,max_prefix,tag_index_no;
	string records, clas[1000][2];
	//reading of classes
	ofstream log1;
	log1.open("logs/no_id_records.txt");
	
	ifstream classes;
	classes.open("initialization/classes.txt");
	z=0;
	cout<< "Loading classes..."<<endl;
	if (classes.is_open()) {
		while(!classes.eof()){
			getline(classes,records);
			if(records[0]=='['){
				int temp=records.find("]");
				clas[z][0]=records.substr(0,temp+1);
				clas[z][1]=records.substr(temp+2);
			}
			else{
				int temp=records.find_last_of('\t');
				clas[z][0]=records.substr(0,temp);
				clas[z][1]=records.substr(temp+1);
			}
			cout<<clas[z][0]<<'\t'<<'\t'<<clas[z][1]<<endl;
			z++;
		}
		max_clas=z;
		cout << max_clas<<endl;
	}
	else {
		cout<< "The file classes.txt does not exist. Make sure there is a proper syntaxed file named classes.txt in the folder";
		return 0;
	}
	classes.close();


	//reading of the mappings
	ifstream mappings;
	
	mappings.open("initialization/mappings.txt");
	z=0;
	int invalid_mappings=0;
	cout << "Loading mappings..."<<endl;
	if (mappings.is_open()) {
		while(!mappings.eof()){
			mappings >> map[z][0]>>map[z][1]>>map[z][2];
			if(map[z][2]!=""){
			cout << map[z][0]<<"||"<<map[z][1]<<"||"<<map[z][2]<<endl;
			z++;
			}
			else {
				invalid_mappings++;
				cout << "WARNING!!!!!!Mapping with field tag "<<map[z][0]<<" and subfield " << map[z][1]<< " is empty!!!Please check the file mappings.txt"<<endl;
				}
			
		}
		max_fields=z;
		mappings.close();
		cout<< "Valid mappings #: "<<max_fields<<"                               "<<"Invalid mappings #: "<< invalid_mappings<<endl<<endl<<endl;
	}
	else {
		cout<< "The file mappings.txt does not exist. Make sure there is a proper syntaxed file named mappings.txt in the folder";
		return 0;
	}
	
	//reading of prefixes
	ifstream prefixes;
	ofstream rdf;
	rdf.open("rdf/rdfdata.n3");
	prefixes.open("initialization/prefixes.txt");
	z=0;
	cout<< "Loading prefixes..."<<endl;
	if (prefixes.is_open()) {
		while(!prefixes.eof()){
			getline (prefixes,prefix[z]);
			rdf << prefix[z];
			cout << prefix[z]<<endl;
			z++;
		}
		max_prefix=z;
		cout << max_prefix<<endl;
	}
	else {
		cout<< "The file prefixes.txt does not exist. Make sure there is a proper syntaxed file named prefixes.txt in the folder";
		return 0;
	}
	rdf<<endl;
	//anoigma arxeiwn
	
	ifstream bib;
	ofstream line1;
	//bib.open("data/NLGauth0313new.iso2709");
	bib.open("data/records.iso2709");
	cout<<"Loading records, please standby..."<<endl;
	//setlocale(LC_ALL, "");
	
	if (bib.is_open()==0){
		cout << "The file records.iso2709 does not exist. Make sure there is a proper syntaxed file named records.iso2709 in the folder";
		return 0;
	}
	//open rdf file to write triplets
	// start of data reading line by line


	line1.open("data/line_records_sample100.iso2709");
	tag_index_no=1;
	int record1=1;
	//for (z=0;z<1000;z++){
	while (!bib.eof( )) {
		string line;
		getline(bib,line,'\035');
		if (line.length()==0){
			break;
		}
		record myRecord = RecordExtractor(line, record1,clas,max_clas);

		int temp = FieldFind(myRecord,"001");
		string tempsub;
		string mySubject;
		if (temp!=-1){
			tempsub = myRecord.field[temp].subfield.nosub;
			mySubject = Connector("library:record",StringClean(tempsub));
		}
		else{
			log1<<"Error:Record number "<<record1<<" does not have a proper 001 field"<<"\n";
			record1++;
			continue;
		}
		//cout << mySubject<<"||"<<myRecord.field[temp].subfield.nosub<<endl;
		//RecordPrint(myRecord);

		string myRDF = RDFtransformer(myRecord,mySubject, map, max_fields);
		if (myRDF[0]!='['){
			rdf << myRDF;
		}
		else {
			log1<<myRDF;
		}

		line1<<line<<'\n';
		cout<<"||"<<record1<<"||"<<"OK"<<"||"<<myRecord.type<<'\n';
		record1++;
		string mpourdes;
		//cin>>mpourdes;
	}
	
	line1.close();
	return 0;
}
