#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<ctime>
#include<cstring>
#include<string>
#include<vector>
#include<conio.h>
#include<windows.h>
#include<sstream>
using namespace std;

char usrp = '0', var, ulp = 201, mp = 205, urp = 187, llp = 200, lrp = 188, vp = 186, 
		 sp = ' ';

string choice= "",
	   name= "",
	   out= "",
	   out1= "";

float equip[25][25];
int armor[25];

//Player Booleans
bool pturn=false,
	 pcrit=false,
	 meleecheck=false,
	 pcountercheck=false,
	 kimax=false,
	 focuskiused= false,
	 multipunchtech=true,
	 mpunchused=false,
     multikicktech=true,
	 mkickused=false,
     sensekitech=true,
     zanzokentech=true,
	 blocktech=true,
	 barriertech=true,
	 block=false,
	 barrier=false,
	 zanzo=false,
     solarflaretech=true,
	 solarflareused=false,
	 sf=false, 
	 tired=false,
	 destroy=false,
	 saiyanArmorB=true,
	 saiyanArmorA=true,
	 saiyanArmorE=true,
	 wcloth15=true,
	 wcloth25=true,
	 wcloth50=true,
	 wcloth75=true,
	 wcloth100=true;

//Computer Booleans
bool ccrit=false,
	 ccountercheck=false,
	 ckimaxbool=false,
	 compfocuskiused=false,
	 ctired=false,
	 compsolarflaretech=true,
	 compsolarflareused=false,
	 compzanzotech=true,
	 compzanzo=false,
	 compblocktech=true,
	 compmultipunchtech=true,
	 compmpunchused=false,
	 compmultikicktech=true,
	 compmkickused=false,
	 compbarriertech=true,
	 compbarrier= false;

//Player Integers	
int	plvl=1,
	php=50,
	pki=15,
	psp=0,
	str=0,
	stm=0, 
	dex=0,
	spd=0, 
	wis=0,
	strmax=str,
	stmmax=stm,
	dexmax=dex,
	spdmax=spd,
	wismax=wis,
	x=0,
	y=0,
	count=0,
	check=0,
	pint=0,
	patk=0,
	pdod=0,
	pdmg=0,
	pbean=2,
	strbns=(str-12)/2,
	stmbns=(stm-12)/2, 
	dexbns=(dex-12)/2,
	spdbns=(spd-12)/2,
	wisbns=(wis-12)/2,
	intbns=(spdbns+wisbns)/2,
	intbnsmax=intbns,
	dexbnsmax=0,
	spdbnsmax=0,	
	apr=(spd+dex)/12,
	aprmax=apr,
	phpmod=(stmbns*8)+(plvl*10),
	pkimod=(wisbns*2)+(plvl*5),
	nhpmod=(((stm-12)/2)*(plvl+1))*5+(plvl+1)*15,
	nkimod=(((wis-12)/2)*(plvl+1))+(plvl+1)*5,
	phpmax=0,
	pkimax=0,
	pl=((php+(pki*2))+((wis+stm)*3))*(pow(str+spd,1.5))/50*plvl,
	xp=0,
	nxtxp=150,
	zeni=0,
	barrierhp=0,
	parmorhp=0,
	basicarmorhp,
	advancedarmorhp,
	elitearmorhp,
	wtxp=0,
	strxp=0,
	stmxp=0,
	dexxp=0,
	spdxp=0,
	wisxp=0,
	punchxp=0,
	doubleaxehandlexp=0,
	elbowxp=0,
	headbuttxp=0,
	kickxp=0,
	kneexp=0,
	roundhousexp=0,
	kiblastxp=0,
	dondonpaxp=0,
	sensekixp=0,
	blockxp=0,
	focuskixp=0,
	multipunchxp=0,
	multikickxp=0,
	solarflarexp=0,
	zanzokenxp=0,
	barrierxp=0,
	rnd=0,
	aprc=0,
	mpc=0,
	mpcc=0,
	mkc=0,
	mkcc=0,
	sfc=0,
	cc=0,
	dhold=0;

//Computer Integers
int	clvl=1, 
	chp=50, 
	cki=15,
	csp=0, 
	cstr=0, 
	cstm=0, 
	cdex=0,
	cspd=0, 
	cwis=0,
	cwismax=0,
	cint=0,
	catk=0,
	cdod=0,
	cdmg=0,
	cbean=2,
	cmpc=0,
	cmkc=0,
	csfc=0,
	cstrbns=(cstr-12)/2, 
	cstmbns=(cstm-12)/2, 
	cdexbns=(cdex-12)/2, 
	cwisbns=(cwis-12)/2,
	cspdbns=(cspd-12)/2,
	cintbns=(cdexbns+cwisbns)/2,
	capr=(cspd+cdex)/10,
	chpmod=(cstmbns*8)+(clvl*10),
	ckimod=(cwisbns*2)+(clvl*5),
	cpl=((chp+(cki*2))+((cwis+cstm)*3))*(pow(cstr+cspd,1.5))/50*clvl,
	cplmax=0,
	chpmax=0,
	ckimax=0,
	cblock=0,
	compbarrierhp=0,
	carmorhp=0,
	compRestChoice=0,
	compKiChoice=0,
	compBeanChoice=0,
	compZanzoChoice=0,
	compBarrierChoice=0,
	compmPunchChoice=0,
	compmKickChoice=0;

int mainmenu();
int battle();
int train();
int store();
int save();
int load();
int creation();
int computerturn();
int playerturn();
int menu();
int killscreen();

void story();
void charcreation();
void charscreen();
void pause();

int main()
{
	
	unsigned seed = time(0); 
	srand(seed);

	do
	{
		system("CLS");
		cout << "\t\t\t *Dragon Ball Z: Legends*" << endl << endl
			 << "\t\t\t     " << ulp << setw(15) << setfill(mp) << urp << endl
		     << "\t\t\t     " << vp << setw(15) << setfill(sp) << vp << endl
			 << "\t\t\t     " << vp << setw(14) << left << " 1. New Game" << vp << endl
			 << "\t\t\t     " << vp << setw(14) << " 2. Load Game" << vp << endl
			 << "\t\t\t     " << vp << setw(15) << right << setfill(sp) << vp << endl
			 << "\t\t\t     " << llp << setw(15) << setfill(mp) << lrp << endl << endl << setfill(sp)
			 << "What would you like to do? ";

		usrp = getch();
	}
	while(usrp != '1' && usrp != '2');

	if(usrp == '1')
		charcreation();

	else
		load();

	story();

}

void story()
{

	
}


int mainmenu()
{
	
	do
	{
		system("CLS");
		cout << "\t\t\t *Dragon Ball Z: Legends*" << endl << endl
			 << "\t\t\t     " << ulp << setw(15) << setfill(mp) << urp << endl
		     << "\t\t\t     " << vp << setw(15) << setfill(sp) << vp << endl
			 << "\t\t\t     " << vp << setw(14) << left << " 1. Save Game" << vp << endl
			 << "\t\t\t     " << vp << setw(14) << " 2. Status" << vp << endl
			 << "\t\t\t     " << vp << setw(14) << " 3. Training" << vp << endl
			 << "\t\t\t     " << vp << setw(14) << " 4. Fight" << vp << endl
			 << "\t\t\t     " << vp << setw(14) << " 5. Store" << vp << endl
			 << "\t\t\t     " << vp << setw(14) << " 6. Quit Game" << vp << endl
			 << "\t\t\t     " << vp << setw(15) << right << setfill(sp) << vp << endl
			 << "\t\t\t     " << llp << setw(15) << setfill(mp) << lrp << endl << endl << setfill(sp)
			 << "What would you like to do? ";
		usrp = getch();

		if(usrp == '1')
		{
			cout << "\n\nThis will overwrite current save game, are you sure? (Y/N): ";
			usrp = toupper(getch());
	
				if(usrp == 'Y')	
					save();
	
				else
					usrp = 0;
		}
	
		else if(usrp == '2')
			menu();

//	else if(usrp == '3')
		//train();

//	else if(usrp == '4')
		//battle();
		
//	else
		//store();

		else if(usrp == '6')
		{
				cout << "\n\nAre sure you would like to Quit? (Y/N): ";
				usrp = toupper(getch());
	
			if(usrp == 'Y')
				break;

			else if(usrp == 'N')
				usrp = 0;
		}

	}
	while(usrp != '6');

	exit(0);
}

void charcreation()
{
	
	do
	{
		plvl= 1;
		php = 50;
		pki = 15; 
		xp = 0;
		phpmax = php;
		pkimax = pki;
	
		str = (7 + rand() % 10);
		stm = (7 + rand() % 10);
		dex = (7 + rand() % 10);
		wis = (7 + rand() % 10);
		spd = (7 + rand() % 10);
	
		strmax=(str+(strxp/100));
		stmmax=(stm+(stmxp/100));
		dexmax=(dex+(dexxp/100));
		spdmax=(spd+(spdxp/100));
		wismax=(wis+(wisxp/100));
		
		dexbns = (dex-12)/2;
		wisbns = (wis-12)/2;
		stmbns = (stm-12)/2;
		strbns = (str-12)/2;
		spdbns = (spd-12)/2;
	
			if(stmbns < 0)
				stmbns = -2;	
	
		dexbnsmax = dexbns;
		spdbnsmax = spdbns;
	
		phpmod = (stmbns*8)+(plvl*10);
		pkimod = (wisbns*2)+(plvl*5);
	
		php = php+phpmod;
		pki = pki+pkimod;
		phpmax = php;
		pkimax = pki;
	
		psp = stm;
		apr = (dex+spd)/12;
		
		nhpmod = (stmbns*8)+((plvl+1)*10);
		nkimod = (wisbns*2)+((plvl+1)*5);
		intbns = (spdbns+wisbns)/2;
	
		pl=((php+(pki*2))+((wis+stm)*3))*(pow(str+spd,1.5))/50*plvl;
		
		system("CLS");
		cout << "HUMAN MARTIAL ARTIST\n";
		cout << "LVL: " << plvl << endl << endl;
		cout << "HP: " << php << "/" << phpmax << endl;
		cout << "KI: " << pki << "/" << pkimax << endl;
		cout << "SP: " << psp << "/" << stm << endl;
		cout << "APR: " << apr << endl << endl;
		cout << "WIS: " << wis << endl;
		cout << "STM: " << stm << endl;
		cout << "STR: " << str;
	
		cout << "\nDEX: " << dex;
		cout << "\nSPD: " << spd;
		cout << "\n\nWith current stats: " << endl;
		cout << "-------------------" << endl;
		cout << "+" << nhpmod << " HP nxt LVL" << endl;
		cout << "+" << nkimod << " KI nxt LVL" << endl << endl;
	
		if(intbns >= 0)
			cout << "+"; 
			cout << intbns << " INITIVE\n";
		
		if(dexbns >= 0)
			cout << "+";
			cout << dexbns << " MELEE ATTACK";

		if(zanzo)
			cout << " (+" << (zanzokenxp/100+2) << ")";				
	
		cout << endl;
	
		if(wisbns >= 0)
			cout << "+";
			cout << wisbns << " KI ATTACK";

		if(kimax)
			cout << "    (+" << (focuskixp/100+2) << ")";
	
		cout << endl;

		if(strbns >= 0)
			cout << "+";
			cout << strbns << " MELEE DMG\n";

		if(wisbns >= 0)
			cout << "+";
			cout << wisbns << " KI DMG";

		if(kimax)
			cout << "       (+" << (focuskixp/100+2) << ")";
	
		cout << endl;
	
		if(dexbns >= 0)
			cout << "+";
			cout << dexbns << " MELEE DODGE";

		if(zanzo)
			cout << "  (+" << (zanzokenxp/100+2) << ")";	
	
		cout << endl;
	
		if(spdbns >= 0)
			cout << "+";
			cout << spdbns << " KI DODGE";

		if(zanzo)
			cout << "     (+" << (zanzokenxp/100+2) << ")";
	
		cout << "\n\nPower Level: " << pl << endl << endl;
	
		cout << "Re-roll or Keep? <R/K>: ";
		choice = getch();

		if (choice != "r" && choice != "k")
		{
			do
			{
			cout << "Press 'R' or 'K'! ";
			choice = getch();
			cout << "\nRe-roll or Keep? <R/K>: ";
			}
			while (choice != "r" && choice != "k");
		}	
	}
	while(choice == "r" && choice != "k");

	cout << "\n\nWhat would you like to name your character? ";
	cin >> name;

	charscreen();

}

void charscreen()
{
	
	system("CLS");
	cout << "\t\tYour *Dragon Ball Z: Legends* Character\n\n";
	cout << name << endl;
	cout << "HUMAN MARTIAL ARTIST\n";
	cout << "LVL: " << plvl << endl;
	cout << "XP: " << xp << "/" << nxtxp << endl << endl;
	cout << "HP: " << php << "/" << phpmax;

		if(parmorhp > 0)
			cout << " [" << parmorhp << "]";
	
		if(barrier && barrierhp > 0)
			cout << " (" << barrierhp << ")";

	cout << "\nKI: " << pki << "/" << pkimax << endl;
	cout << "SP: " << psp << "/" << stm << endl;
	cout << "APR: " << apr << endl << endl;
	cout << "WIS: " << wis;
		if(wis < wismax)
			cout << " (-" << (wismax-wis) << ")";
		if(wis > wismax)
			cout << " (+" << (wis-wismax) << ")";
	cout << "\nSTM: " << stm;
		if(stm < stmmax)
			cout << " (-" << (stmmax-stm) << ")";
		if(stm > stmmax)
			cout << " (+" << (stm-stmmax) << ")";
	cout << "\nSTR: " << str;
		if(str < strmax)
			cout << " (-" << (strmax-str) << ")";
		if(str > strmax)
			cout << " (+" << (str-strmax) << ")";
	cout << "\nDEX: " << dex;
		if(dex < dexmax)
			cout << " (-" << (dexmax-dex) << ")";
		if(dex > dexmax)
			cout << " (+" << (dex-dexmax) << ")";
	cout << "\nSPD: " << spd;
		if(spd < spdmax)
			cout << " (-" << (spdmax-spd) << ")";
		if(spd > spdmax)
			cout << " (+" << (spd-spdmax) << ")";

	cout << "\n\nWith current stats: " << endl;
	cout << "-------------------" << endl;
	cout << "+" << nhpmod << " HP nxt LVL" << endl;
	cout << "+" << nkimod << " KI nxt LVL" << endl << endl;

		if(intbns >= 0)
			cout << "+"; 
			cout << intbns << " INITIVE\n";
		
		if(dexbns >= 0)
			cout << "+";
			cout << dexbns << " MELEE ATTACK";

		if(zanzo)
			cout << " (+" << (zanzokenxp/100+2) << ")";				

	cout << endl;

		if(wisbns >= 0)
			cout << "+";
			cout << wisbns << " KI ATTACK";

		if(kimax)
			cout << "    (+" << (focuskixp/100+2) << ")";

	cout << endl;

		if(strbns >= 0)
			cout << "+";
			cout << strbns << " MELEE DMG\n";

		if(wisbns >= 0)
			cout << "+";
			cout << wisbns << " KI DMG";

		if(kimax)
			cout << "       (+" << (focuskixp/100+2) << ")";

	cout << endl;

		if(dexbns >= 0)
			cout << "+";
			cout << dexbns << " MELEE DODGE";

		if(zanzo)
			cout << "  (+" << (zanzokenxp/100+2) << ")";	

	cout << endl;

		if(spdbns >= 0)
			cout << "+";
			cout << spdbns << " KI DODGE";

		if(zanzo)
			cout << "     (+" << (zanzokenxp/100+2) << ")";	

	pl = ((php+(pki*2))+((wis+stm)*3))*(pow(str+dex,1.5))/50*plvl;
	cout << "\n\nYour current Power Level: " << pl;
	cout << "\nZeni: $" << zeni;

	pause();
	
}

int menu()
{

	do
	{
	system("CLS");
	cout << "\t\t\t*Menu*\n\n"
		 << "1. Character\n"
		 << "2. Melee Attacks\n"
	 	 << "3. Ki Attacks\n"
		 << "4. Abilities\n"
		 << "5. Inventory\n"
		 << "6. Exit\n\n"
		 << "What would you like to do? ";
	usrp = getch();

		if(usrp == '1')
		{
		system("CLS");
		cout << "\t\tYour *Dragon Ball Z: Legends* Character\n\n";
		cout << name << endl;
		cout << "HUMAN MARTIAL ARTIST\n";
		cout << "LVL: " << plvl << endl;
		cout << "XP: " << xp << endl << endl;
		cout << "HP: " << php << "/" << phpmax << endl;
		cout << "KI: " << pki << "/" << pkimax << endl;
		cout << "SP: " << psp << "/" << stm << endl;
		cout << "APR: " << apr << endl << endl;
		cout << "STR: " << str << endl;
		cout << "STM: " << stm << endl;
		cout << "DEX: " << dex << endl;
		cout << "SPD: " << spd << endl;
		cout << "WIS: " << wis << endl << endl;
		cout << "With current stats: " << endl;
		cout << "-------------------" << endl;
		cout << "+" << nhpmod << " HP nxt LVL" << endl;
		cout << "+" << nkimod << " KI nxt LVL" << endl << endl;
		cout << "+" << intbns << " INITIVE" << endl;
		cout << "+" << dexbns << " MELEE ATTACK" << endl;
		cout << "+" << wisbns << " KI ATTACK" << endl;
		cout << "+" << strbns << " MELEE DMG" << endl;
		cout << "+" << wisbns << " KI DMG" << endl;
		cout << "+" << dexbns << " MELEE DODGE" << endl;
		cout << "+" << spdbns << " KI DODGE" << endl << endl;
		pl = ((php+(pki*2))+((wis+stm)*3))*(pow(str+dex,1.5))/50*plvl;
		cout << "Your current Power Level: " << pl << endl << endl;
		system("Pause");
		}

		if(usrp == '2')
		{
		system("CLS");
		cout << "Melee Attacks" << setw(34) << "XP %\n"
			 << "-------------" << setw(35) << "----\n\n"
			 << "Double Axe Handle [LVL: " << (doubleaxehandlexp/100)+1 << "]" << setw(19) << doubleaxehandlexp % 100 << "%\n"
			 <<	"Strike +6" << endl << "Dodge  +0" << endl
			 << "Damage 1d" << (4 + (((doubleaxehandlexp+100)/200)));
				if(doubleaxehandlexp > 199)
					cout << "+" << (doubleaxehandlexp/200);
		cout <<	"\n\nHeadbutt          [LVL: " << (headbuttxp/100)+1 << "]" << setw(19) << headbuttxp % 100 << "%\n"
			 <<	"Strike +4" << endl << "Dodge  +0" << endl
			 << "Damage 1d" << (6 + (((headbuttxp+100)/200)));
				if(headbuttxp > 199)
					cout << "+" << (headbuttxp/200);
		cout <<	"\n\nElbow             [LVL: " << (elbowxp/100)+1 << "]" << setw(19) << elbowxp % 100 << "%\n"
			 <<	"Strike +2" << endl << "Dodge  +0" << endl
			 << "Damage 1d" << (8 + (((elbowxp+100)/200)));
				if(elbowxp > 199)
					cout << "+" << (elbowxp/200);
		cout << "\n\nPunch             [LVL: " << (punchxp/100)+1 << "]" << setw(19) << punchxp % 100 << "%\n"
			 <<	"Strike +0" << endl << "Dodge  +0" << endl
			 << "Damage 1d" << (10 + (((punchxp+100)/200)));
				if(punchxp > 199)
					cout << "+" << (punchxp/200);
		cout <<	"\n\nKnee              [LVL: " << (kneexp/100)+1 << "]" << setw(19) << kneexp % 100 << "%\n"
			 <<	"Strike +0" << endl << "Dodge  +2" << endl
			 << "Damage 2d" << (6 + (((kneexp+100)/200)));
				if(kneexp > 199)
					cout << "+" << (kneexp/200)*2;
		cout << "\n\nKick              [LVL: " << (kickxp/100)+1 << "]" << setw(19) << kickxp % 100 << "%\n"
			 <<	"Strike +0" << endl << "Dodge  +4" << endl
			 << "Damage 2d" << (8 + (((kickxp+100)/200)));
				if(kickxp > 199)
					cout << "+" << (kickxp/200)*2;
		cout << "\n\nRound House Kick  [LVL: " << (roundhousexp/100)+1 << "]" << setw(19) << roundhousexp % 100 << "%\n"
			 <<	"Strike +0" << endl << "Dodge  +6" << endl
			 << "Damage 2d" << (10 + (((roundhousexp+100)/200)));
				if(roundhousexp > 199)
					cout << "+" << (roundhousexp/200)*2;

			if(multipunchtech)
				cout << "\n\nMulti-Punch       [LVL: " << (multipunchxp/100)+1 << "]" << setw(19) << multipunchxp % 100 << "%\n";

			if(multikicktech)
				cout << "\n\nMulti-Kick        [LVL: " << (multikickxp/100)+1 << "]" << setw(19) << multikickxp % 100 << "%\n";
	
		cout << endl;
		system("Pause");
		}

		if(usrp == '3')
		{
		system("CLS");
		cout << "Ki Attacks" << setw(24) << "XP %\n"
			 << "----------" << setw(25) << "----\n\n"
			 << "Ki Blast   [LVL: " << (kiblastxp/100)+1 << "]" << setw(9) << kiblastxp % 100 << "%\n"
			 << "Dondonpa   [LVL: " << (dondonpaxp/100)+1 << "]" << setw(9) << dondonpaxp % 100 << "%\n";

		cout << endl;
		system("Pause");
		}

		if(usrp == '4')
		{
		system("CLS");
		cout << "Abilities" << setw(26) << "XP %\n"
			 << "---------" << setw(27) << "----\n\n"
			 << "Focus Ki\n";

			if(sensekitech)
				cout << "Sense Ki (passive)	[LVL: " << (sensekixp/100)+1 << "]" << setw(9) << sensekixp % 100 << "%\n";

			if(blocktech)
				cout << "Block    (Passive)	[LVL: " << (blockxp/100)+1 << "]" << setw(9) << blockxp % 100 << "%\n";

			if(solarflaretech)
				cout << "Solar Flare 	        [LVL: " << (solarflarexp/100)+1 << "]" << setw(9) << solarflarexp % 100 << "%\n";

			if(zanzokentech)
				cout << "Zanzoken 	        [LVL: " << (zanzokenxp/100)+1 << "]" << setw(9) << zanzokenxp % 100 << "%\n";

		cout << endl;
		system("Pause");
		}

		if(usrp == '5')
		{
		system("CLS");
		cout << "\t\tInventory\n\n"
			 << "[Zeni: $" << zeni << "]" << endl << endl
			 << pbean << " Senzu Bean(s)\n";

		cout << endl;
		system("Pause");
		}
	}
	while(usrp != '6');	

	mainmenu();

}

int save()
{
	ofstream file;
	file.open("DBZ_Save.sav");

	file << kimax << endl;
	file <<	ckimaxbool << endl;
	file << multipunchtech << endl;
    file << multikicktech << endl;
    file << sensekitech << endl;
    file << zanzokentech << endl;
	file << blocktech << endl;
	file << barriertech << endl;
	file << block << endl;
	file << barrier << endl;
	file << zanzo << endl;
    file << solarflaretech << endl;
	file << sf << endl;
	file << tired << endl; 
	file << ctired << endl;
	file << choice << endl;
	file << plvl << endl;
	file << php << endl;
	file << pki << endl;
	file << psp << endl;
	file << str << endl;
	file << stm << endl;
	file << dex << endl;
	file << spd << endl;
	file << wis << endl;
	file << wismax << endl;
	file << pint << endl;
	file << patk << endl;
	file << pdod << endl;
	file << pdmg << endl;
	file << pbean << endl;
	file << strbns << endl;
	file << stmbns << endl; 
	file << dexbns << endl;
	file << spdbns << endl;
	file << wisbns << endl;
	file << intbns << endl;
	file << dexbnsmax << endl;
	file << spdbnsmax << endl;
	file << apr << endl;
	file << phpmod << endl;
	file << pkimod << endl;
	file << nhpmod << endl;
	file << nkimod << endl;
	file << phpmax << endl;
	file << pkimax << endl;
	file << pl << endl;
	file << xp << endl;
	file << nxtxp << endl;
	file << zeni << endl;
	file << punchxp << endl;
	file << doubleaxehandlexp << endl;
	file << elbowxp << endl;
	file << headbuttxp << endl;
	file << kickxp << endl;
	file << kneexp << endl;
	file << roundhousexp << endl;
	file << kiblastxp << endl;
	file << dondonpaxp << endl;
	file << sensekixp << endl;
	file << blockxp << endl;
	file << focuskixp << endl;
	file << multipunchxp << endl;
	file << multikickxp << endl;
	file << solarflarexp << endl;
	file << zanzokenxp << endl;
	file << rnd << endl;
	file << aprc << endl;
	file << mpc << endl;
	file << mkc << endl;
	file << sfc << endl;
	file << cc << endl;
	file << clvl << endl; 
	file << chp << endl; 
	file << cki << endl;
	file << csp << endl; 
	file << cstr << endl; 
	file << cstm << endl; 
	file << cdex << endl;
	file << cspd << endl; 
	file << cwis << endl;
	file << cwismax << endl;
	file << cint << endl;
	file << catk << endl;
	file << cdod << endl;
	file << cdmg << endl;
	file << cbean << endl;
	file << cmpc << endl;
	file << cmkc << endl;
	file << csfc << endl;
	file << cstrbns << endl;
	file << cstmbns << endl; 
	file << cdexbns << endl;
	file << cwisbns << endl;
	file << cspdbns << endl;
	file << cintbns << endl;
	file << capr << endl;
	file << chpmod << endl;
	file << ckimod << endl;
	file << cpl << endl;
	file << cplmax << endl;
	file << chpmax << endl;
	file << ckimax << endl;
	file << compRestChoice << endl;
	file << compKiChoice << endl;
	file << compBeanChoice << endl;
	file << name;
	
	file.close();

	cout << "\n\nYour game has been saved! ";

	usrp = getch();
	mainmenu();
}

int load()
{
	ifstream ifile;
	ifile.open("DBZ_Save.sav");

	ifile >> kimax;
	ifile >> ckimaxbool;
	ifile >> multipunchtech;
    ifile >> multikicktech;
    ifile >> sensekitech;
    ifile >> zanzokentech;
	ifile >> blocktech;
	ifile >> barriertech;
	ifile >> block;
	ifile >> barrier;
	ifile >> zanzo;
    ifile >> solarflaretech;
	ifile >> sf;
	ifile >> tired; 
	ifile >> ctired;
	ifile >> choice;
	ifile >> plvl;
	ifile >> php;
	ifile >> pki;
	ifile >> psp;
	ifile >> str;
	ifile >> stm;
	ifile >> dex;
	ifile >> spd;
	ifile >> wis;
	ifile >> wismax;
	ifile >> pint;
	ifile >> patk;
	ifile >> pdod;
	ifile >> pdmg;
	ifile >> pbean;
	ifile >> strbns;
	ifile >> stmbns; 
	ifile >> dexbns;
	ifile >> spdbns;
	ifile >> wisbns;
	ifile >> intbns;
	ifile >> dexbnsmax;
	ifile >> spdbnsmax;
	ifile >> apr;
	ifile >> phpmod;
	ifile >> pkimod;
	ifile >> nhpmod;
	ifile >> nkimod;
	ifile >> phpmax;
	ifile >> pkimax;
	ifile >> pl;
	ifile >> xp;
	ifile >> nxtxp;
	ifile >> zeni;
	ifile >> punchxp;
	ifile >> doubleaxehandlexp;
	ifile >> elbowxp;
	ifile >> headbuttxp;
	ifile >> kickxp;
	ifile >> kneexp;
	ifile >> roundhousexp;
	ifile >> kiblastxp;
	ifile >> dondonpaxp;
	ifile >> sensekixp;
	ifile >> blockxp;
	ifile >> focuskixp;
	ifile >> multipunchxp;
	ifile >> multikickxp;
	ifile >> solarflarexp;
	ifile >> zanzokenxp;
	ifile >> rnd;
	ifile >> aprc;
	ifile >> mpc;
	ifile >> mkc;
	ifile >> sfc;
	ifile >> cc;
	ifile >> clvl; 
	ifile >> chp; 
	ifile >> cki;
	ifile >> csp; 
	ifile >> cstr; 
	ifile >> cstm; 
	ifile >> cdex;
	ifile >> cspd; 
	ifile >> cwis;
	ifile >> cwismax;
	ifile >> cint;
	ifile >> catk;
	ifile >> cdod;
	ifile >> cdmg;
	ifile >> cbean;
	ifile >> cmpc;
	ifile >> cmkc;
	ifile >> csfc;
	ifile >> cstrbns;
	ifile >> cstmbns; 
	ifile >> cdexbns;
	ifile >> cwisbns;
	ifile >> cspdbns;
	ifile >> cintbns;
	ifile >> capr;
	ifile >> chpmod;
	ifile >> ckimod;
	ifile >> cpl;
	ifile >> cplmax;
	ifile >> chpmax;
	ifile >> ckimax;
	ifile >> compRestChoice;
	ifile >> compKiChoice;
	ifile >> compBeanChoice;
	ifile >> name;
	
	ifile.close();

	cout << "\n\nYour game has been loaded! ";
	usrp = getch();

	mainmenu();
	
}

void pause()
{

	cout << endl << endl;

	while(usrp != 32)
	{
		cin.clear();
		cout << "(Press SPACE to continue) . . . ";
		usrp = toupper(getch());
		cout << endl;
	}

	system("CLS");
	usrp = 0;
	return;
}

int senseki()
{
	
	cpl = (((chp+(cki*2))+((cwis+cstm)*3))*(pow(cstr+cspd,1.5))/50*clvl);
	cc = (1 + rand() % 100)+((sensekixp/100)*10);

	cout << "\n\nYou attempt to sense your opponent's Power Level!\n";

	if(cc > 75)
	{
		cout << "Your attempt succeded! [" << cpl << "]";		
		sensekixp++;
	}

	else
		cout << "Your attempt failed!";	
}
