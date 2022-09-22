#include<iostream>
#include<time.h>
#pragma warning(disable:4996)
using namespace std;


#define NAME_SIZE 30
#define ITEM_DESC 128
#define SKILL_DESC 300



//게임 메뉴
enum MENU_MAIN_GAME
{
    MM_None,
    Map,
    Store,
    Inventory,
    Exit

};
//맵 메뉴
enum MENU_MAP
{
    M_None,
    Desert,
    Forest,
    Basement
};
enum MonsterName
{
    Mouse,
    WildBoar,
    Orc,
    Dragon
};
//전투 메뉴
enum MENU_BATTLE
{
    MB_None,
    Fight,
    GetaWay
};
//상점 메뉴
enum MENU_STORE
{
    Buy=1,
    Sell,
    MS_None=0,
    Weapon,
    Armor,
    back=10
};
enum MENU_INVENTORY
{
    MI_None,
    MI_ItemChange,
    MI_SkillChange,
    MI_Exit
};
enum ITEM_TYPE //무기 타입
{
    IT_ARMOR,
    IT_WEAPON,
    IT_MAX,
    IT_NONE=0

};

enum Skill_Slot
{
    Slot_1,
    Slot_2,
    Slot_3,
    Slot_4,
    Slot_Max,
    P_Slot_Max = 3,
    Inventory_Slot = 5
};
enum Item_Slot
{
    Item_Slot_1,
    Item_Slot_2,
    Item_Slot_3,
    Item_Slot_4,
    Item_Slot_Max
};
enum Skill_TYPE
{
    Skill_type_None,
    Skill_type_Damage,
    Skill_type_Buff_Attack,
    Skill_type_Buff_Armor,
    Skill_type_Debuff_Attack,
    Skill_type_Debuff_Armor
};
struct Skill//스킬 마나를 소모하면서 피해 증가
{
    Skill_TYPE Type;
    char Name[NAME_SIZE] = {};
    char Decs[SKILL_DESC] = {};
    float Damage = 0;
    float Mp = 0;

    float Buff_Armor = 0;
    float Buff_Attack = 0;
    float Debuff_Armor = 0;
    float Debuff_Attack = 0;
};
//직업
enum JOB
{
    JB_None,
    Warrior,
    Wizard
};
enum EQUIP
{
    EQ_Armor,
    EQ_Weapon,
    EQ_Equip_Max = 2
};
struct Job_Warrior
{
    //시작 능력치
    float Mp_start = 100;
    float Hp_start = 300;
    int Mp_Max_start = 120;
    int Hp_Max_start = 500;
    float Attack_start = 20;
    float Defence_start = 50;

    //성장치
    float Mp_growth = 10;
    float Hp_growth = 30;
    int Mp_Max_growth = 10;
    int Hp_Max_growth = 40;
    float Attack_growth = 7;
    float Defence_growth = 10;

    //스킬

    Skill Warrior_Skill_List[Slot_Max] = {};

};
struct Job_Wizard
{
    //시작 능력치
    float Mp_start = 150;
    float Hp_start = 200;
    int Mp_Max_start = 500;
    int Hp_Max_start = 200;
    float Attack_start = 50;
    float Defence_start = 20;

    //성장치
    float Mp_growth = 30;
    float Hp_growth = 10;
    int Mp_Max_growth = 40;
    int Hp_Max_growth = 10;
    float Attack_growth = 10;
    float Defence_growth = 7;
 
    //스킬

    Skill Wizard_Skill_List[Slot_Max] = {};
};
struct ITEM
{
    ITEM_TYPE Item_type= IT_NONE;// 아이템 타입 
    char Item_Dec[ITEM_DESC] = {};//아이템 설명
    char Item_Name[NAME_SIZE] = {};
    char Item_TypeName[NAME_SIZE] = {};

    float Attack = 0;
    float Defence = 0;

    int Price = 0;
    int Sell = 0;
};
struct Player
{
    char Name[NAME_SIZE] = {};
    float Mp = 0;
    float Hp = 0;
    int Mp_Max = 0;
    int Hp_Max = 0;

    float Attack = 0;
    float Defence = 0;

    //성장치
    float Mp_growth = 0;
    float Hp_growth = 0;
    int Mp_Max_growth = 0;
    int Hp_Max_growth = 0;

    float Attack_growth = 0;
    float Defence_growth = 0;
    
    //경험치
    float EXP = 0;
    int level = 0;


    JOB job;
    Skill skill_Learn_list[Slot_Max] = {};
    Skill skill_sloat[P_Slot_Max] = {};

    ITEM Equip_Slot[IT_MAX];//장비 착용 배열
    bool Equip_BOOL[IT_MAX]={false,false};//장비 착용 유무
    ITEM Inventory[Inventory_Slot];
    int Gold = 0;

};
struct Monster
{
    char Name[NAME_SIZE] = {};
    float Mp = 0;
    float Hp = 0;
    int Mp_Max = 0;
    int Hp_Max = 0;

    float Attack = 0;
    float Defence = 0;

    //성장치
    float Mp_growth = 0;
    float Hp_growth = 0;
    int Mp_Max_growth = 0;
    int Hp_Max_growth = 0;

    float Attack_growth = 0;
    float Defence_growth = 0;

    //경험치
    float EXP = 0;
    int level = 0;

    int DropGold = 0;
};

void MonsterAdvent(int MapCode, Player* player, Monster monster[]);
void Select_job_Inherit_Ability(Player*);
void Learn_Skill(Player*);
void BattlePage(Player**, Monster*);
void Start_game();

void MenuPage();
int MapPage();
void StorePage();
void InventoryPage();
void Change_Item(Player*);
void Change_Skill(Player*);

void Monster_List_Add();
void Store_List_Add();

Monster Monster_List[Slot_Max]; //몬스터 리스트
ITEM Item_List[Item_Slot_Max]; //아이템 리스트
Player player;
static int Choice = 0;
int main() 
{
    srand((unsigned int)time(0));
    
    Start_game();
    Select_job_Inherit_Ability(&player);
    Monster_List_Add();
    Store_List_Add();
    while (true)
    {
        MenuPage();
    }

    return 0;
}

/*
  None,
    Map,
    store,
    inventory,
    exit*/

void Start_game()
{
    char Name[NAME_SIZE] = {};
    while (true)
    {
        system("cls");
        cout << "========== 게임 시작 ==========" << endl;
        cout << "이름: "; cin >> Name;
        strcpy(player.Name, Name);

        cout << "1. 전사\t2.법사" << endl;
        cout << "직업 선택: "; cin >> Choice;
        if (Choice == Warrior)
            player.job = Warrior;
        else
            player.job = Wizard;

        if (cin.fail())//잘못 입력시 되돌리는 기능
        {
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }
        system("pause");
        break;
    }
    
}
void MenuPage()
{
    while (true)
    {
        system("cls");
        cout << "========== 메뉴 ==========" << endl;
        cout << "1.지도\t2.상점\t3.인벤토리\t4.나가기" << endl;
        cout << "선택: "; cin >> Choice;

        if (cin.fail())//잘못 입력시 되돌리는 기능
        {
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }

        switch (Choice)
        {
        case Map:
        {
            int map = MapPage();
            MonsterAdvent(map, &player, Monster_List);
        }    
            break;
            
        case Store:
            StorePage();
            break;
        case Inventory:
           InventoryPage();
                
            break;

        }
        


        system("pause");
    }

}

int MapPage()
{
    while (true)
    {
        system("cls");
        int MapChoice = 0;
        cout << "==========  맵 ==========" << endl;
        cout << "1.사막\t2.숲\t3.지하실\t4.나가기" << endl;
        cout << "선택: "; cin >> MapChoice;
        if (cin.fail())//잘못 입력시 되돌리는 기능
        {
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }

        return MapChoice;
    }
    
     
}

void InventoryPage()
{
    while (true)
    {
        system("cls");
        cout << "==========  인벤토리 및 정보 ==========" << endl;
        cout << "이름:" << player.Name << endl;
        if (player.job == Warrior)
            cout << "직업: 전사" << endl;
        else if (player.job == Wizard)
            cout << "직업: 마법사" << endl;

        cout << "착용아이템: \t" << "방어구: " << player.Equip_Slot[EQ_Armor].Item_Name << "\t무기: " << player.Equip_Slot[EQ_Weapon].Item_Name << endl;

        cout << "HP:" << player.Hp_Max<<"/"<<player.Hp << "\tMP:" << player.Mp_Max<<"/"<<player.Mp << endl;
        cout << "스킬:";
        for (int i = 0; i < Slot_Max; i++)
        {
            cout << player.skill_Learn_list[i].Name << endl;
            cout << "\t" << player.skill_Learn_list[i].Decs << endl << endl;
        }
        cout << "아이템:" << endl;
        for (int i = 0; i < Inventory_Slot; i++)
        {
            if (player.Inventory[i].Item_Name == 0)
            {
                cout<< "[ ]\t";
                continue;
            }
               
            cout << player.Inventory[i].Item_Name << endl;
            cout << "\t" << player.Inventory[i].Item_Dec << endl << endl;
        }

        cout << "1.아이템 변경\t2.스킬슬롯\t3.나가기" << endl;
        cout << "선택:"; cin >> Choice;
        if (cin.fail())//잘못 입력시 되돌리는 기능
        {
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }


        switch (Choice)
        {
        case MI_ItemChange:
        {
            Change_Item(&player);
        }
            break;
        case MI_SkillChange:
        {
            Change_Skill(&player);
        }
            break;
        }

        if (Choice == MI_Exit)
            break;


        system("pause");


    }
}
void Change_Item(Player* p1)
{
    ITEM InstantItemSlote;
    while (true)
    {
        system("cls");
        cout << "=======아이템=======" << endl;             
        cout << "소유 아이템:" << endl;
        for (int i = 0; i < Inventory_Slot; i++)
        {
            if ((* p1).Inventory[i].Item_Name == NULL)
                cout <<i+1<<"." << "\t[ ]";
            cout<<"\t"<< i+1 << "." <<"[" << (*p1).Inventory[i].Item_Name<<"]";

        }

        cout <<endl<< "착용 아이템:";
        cout << "방어구:[" << p1->Equip_Slot[EQ_Armor].Item_Name << "]";
        cout << "\t무기:[" << p1->Equip_Slot[EQ_Weapon].Item_Name << "]" << endl;
        
        cout << "1.방어구\t2.무기" << endl;
        cout << "장착부위 선택:"; cin >> Choice;
        if (cin.fail())//잘못 입력시 되돌리는 기능
        {
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }
        if (Choice == 10)
            break;

        if (Choice <(Slot_1 + 1) || Choice>Inventory_Slot)
            continue;
       
        EQUIP state;
        switch (Choice-1)
        {
        case EQ_Weapon:
        {
            state = EQ_Weapon;
        }       
            break;
        case EQ_Armor:
        {
            state = EQ_Armor;
        }
            break;
        }
       

        cout << "착용할 아이템을 선택하세요(나가기:10):"; cin >> Choice;
        if (cin.fail())//잘못 입력시 되돌리는 기능
        {
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }

        int Inventory_Index = Choice - 1;

        if (p1->Equip_BOOL[state] == true && p1->Inventory[Inventory_Index].Item_type == state)
        {
            InstantItemSlote = p1->Equip_Slot[state];
            p1->Equip_Slot[state] = p1->Inventory[Inventory_Index];
            p1->Inventory[Inventory_Index] = InstantItemSlote;

        }
        else if (p1->Equip_BOOL[state] == false && p1->Inventory[Inventory_Index].Item_type == state)
        {
            p1->Equip_BOOL[state] = true;
            p1->Equip_Slot[state] = p1->Inventory[Inventory_Index];
          

            for (int i = Inventory_Index; i < Inventory_Slot - Inventory_Index - 1; i++)
            {
               
                p1->Inventory[i] = p1->Inventory[i + 1];
                if (p1->Inventory[i].Item_Name == p1->Inventory[i + 1].Item_Name)
                {
                    strcpy(p1->Inventory[i + 1].Item_Name,NULL);
                    
                }
                
            }
               
        }

       

        system("pause");
    }

}
void Change_Skill(Player* p1)
{
    while (true)
    {
        system("cls");
        cout << "=======스킬=======" << endl;
        cout << "등록된 스킬:";
        for (int i = 0; i < P_Slot_Max; i++)
        {
            if (p1->skill_sloat[i].Name == 0)
            {
                cout << "[ ]\t";
                continue;
            }
               

            cout << p1->skill_sloat[i].Name << "\t";
        }
        cout << endl;


        for (int i = 0; i < Slot_Max; i++)
        {
            cout << i + 1 << "." << p1->skill_Learn_list[i].Name << endl;
            cout << "\t" << p1->skill_Learn_list[i].Decs << endl;
        }

        cout << "슬롯에 추가할 스킬을 선택하세요.(나가기:10) :"; cin >> Choice;
        if (cin.fail())//잘못 입력시 되돌리는 기능
        {
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }

        if (Choice == 10)
            break;

        if (Choice <= 0 || Choice > 4)
            continue;

        static int Slot_Index = 0;
        int Skill_Index = Choice - 1;
        
        p1->skill_sloat[Slot_Index] = p1->skill_Learn_list[Skill_Index];
        Slot_Index++;

        if (Slot_Index == P_Slot_Max)
            Slot_Index = 0;

        

        system("pause");
    }
    

}

void Store_List_Add()
{
    strcpy(Item_List[Item_Slot_1].Item_Name, "강철검");
    strcpy(Item_List[Item_Slot_1].Item_Dec, "엄청 강력합니다~");
    strcpy(Item_List[Item_Slot_1].Item_TypeName, "무기구");
    Item_List[Item_Slot_1].Attack = 10;
    Item_List[Item_Slot_1].Defence = 0;
    Item_List[Item_Slot_1].Item_type = IT_WEAPON;
    Item_List[Item_Slot_1].Price = 350;
    Item_List[Item_Slot_1].Sell = Item_List[Item_Slot_1].Price / 2;

    strcpy(Item_List[Item_Slot_2].Item_Name, "천갑옷");
    strcpy(Item_List[Item_Slot_2].Item_Dec, "엄청 튼튼합니다~");
    strcpy(Item_List[Item_Slot_2].Item_TypeName, "방어구");
    Item_List[Item_Slot_2].Attack = 0;
    Item_List[Item_Slot_2].Defence = 10;
    Item_List[Item_Slot_2].Item_type = IT_ARMOR;
    Item_List[Item_Slot_2].Price = 300;
    Item_List[Item_Slot_2].Sell = Item_List[Item_Slot_2].Price / 2;

    strcpy(Item_List[Item_Slot_3].Item_Name, "월석검");
    strcpy(Item_List[Item_Slot_3].Item_Dec, "달모양 칼~");
    strcpy(Item_List[Item_Slot_3].Item_TypeName, "무기구");
    Item_List[Item_Slot_3].Attack = 20;
    Item_List[Item_Slot_3].Defence = -5;
    Item_List[Item_Slot_3].Item_type = IT_WEAPON;
    Item_List[Item_Slot_3].Price = 700;
    Item_List[Item_Slot_3].Sell = Item_List[Item_Slot_3].Price/2;
   
    strcpy(Item_List[Item_Slot_4].Item_Name, "철갑옷");
    strcpy(Item_List[Item_Slot_4].Item_Dec, "튼튼합니다");
    strcpy(Item_List[Item_Slot_4].Item_TypeName, "방어구");
    Item_List[Item_Slot_4].Attack = 0;
    Item_List[Item_Slot_4].Defence = 20;
    Item_List[Item_Slot_4].Item_type = IT_ARMOR;
    Item_List[Item_Slot_4].Price = 1300;
    Item_List[Item_Slot_4].Sell = Item_List[Item_Slot_4].Price / 2;
}

void StorePage()
{
    while (true)
    {
        static int Count = 0;

        system("cls");
        cout << "========== 상점 ==========" << endl;
        for (int i = 0; i < Item_Slot_Max; i++)
        {
            cout << i+1 << "." << Item_List[i].Item_Name <<"["<<Item_List[i].Item_TypeName<<"]" << "\t" << Item_List[i].Item_Dec << endl;
        }
        cout << "1.구매   2.팔기    나가기(10)";

       
        cout <<  "선택:"; cin >> Choice;
        
        if (cin.fail())//잘못 입력시 되돌리는 기능
        {
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }
        if (Choice == back)
            break;

        
        switch (Choice)
        {
        case Buy:
        {
            for (int i = 0; i < Inventory_Slot; i++)
                cout << i + 1 << "." << player.Inventory[i].Item_Name << endl;
            cout << "아이템 선택:"; cin >> Choice;

            if (Choice < Item_Slot_1 || Choice >= Inventory_Slot)
                continue;

            if (Count == Inventory_Slot)
            {
                cout << "인벤토리가 꽉 찼습니다" << endl;
                continue;
            }
            player.Inventory[Count] = Item_List[Choice - 1];
            Count++;

        }
        break;
        case Sell:
        {
            for (int i = 0; i < Inventory_Slot; i++)
                cout <<i+1<<"." << player.Inventory[i].Item_Name << endl;
            cout << "아이템 선택:"; cin >> Choice;

            if (Choice < Item_Slot_1 || Choice > Inventory_Slot)
                continue;
            int InventoryIndex = Choice - 1;
            for (int i = InventoryIndex; i < Inventory_Slot; i++)
            {
                if (InventoryIndex == 4)
                {
                    strcpy(player.Inventory[i].Item_Name, "NULL");
                    
                }
                    

                player.Inventory[i] = player.Inventory[i + 1];
            }
         
            Count--;
        }
        break;
        }

      
       
        

        system("pause");
    }
}

void MonsterAdvent(int MapCode,Player* player, Monster monster[])
{
    int RandomMob = rand() % 100;
    char MapName[NAME_SIZE] = {};
    Monster BattleMob;
    switch (MapCode)//확률별 몬스터 선택
    {
    case Desert:
    {
        strcpy(MapName, "사막");

        if (RandomMob <= 10)
        {
            BattleMob = monster[Dragon];
        }
        else if (RandomMob <= 20)
        {
            BattleMob = monster[Orc];
        }
        else if (RandomMob <= 5)
        {
            BattleMob = monster[WildBoar];
        }
        else
        {
            BattleMob = monster[Mouse];
        }
    }

    break;
    case Forest:
    {
        strcpy(MapName, "숲");
        if (RandomMob <= 5)
        {
            BattleMob = monster[Dragon];
        }
        else if (RandomMob <= 30)
        {
            BattleMob = monster[Orc];
        }
        else if (RandomMob <= 70)
        {
            BattleMob = monster[WildBoar];
        }
        else
        {
            BattleMob = monster[Mouse];
        }
    }

    break;
    case Basement:
    {
        strcpy(MapName, "지하실");
        if (RandomMob <= 5)
        {
            BattleMob = monster[Dragon];
        }
        else if (RandomMob <= 80)
        {
            BattleMob = monster[Orc];
        }
        else
        {
            BattleMob = monster[Mouse];
        }
    }

    break;
    }


    while (true)
    {
        system("cls");
        cout << "========== 몬스터 출현 ==========" << endl;
        cout << "이름: " << BattleMob.Name << "\t레벨: " << BattleMob.level << endl << endl;
        cout << "1. 공격" << "\t2.도망" << endl;
        cout << "선택: "; cin >> Choice;

        if (cin.fail())//잘못 입력시 되돌리는 기능
        {
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }
        if (Choice == Fight)
        {
            BattlePage(&player, &BattleMob);
            break;
        }
        else if (Choice == GetaWay)
        {
            system("cls");
            cout << "도망쳤다." << endl;
            break;

        }

        system("pause");

    }


}
void BattlePage(Player** player, Monster* monster)
{
    while (true)
    {
        system("cls");
        cout << "========== 전투 페이지 ==========" << endl;
        cout << "이름: " << ( *monster).Name << "\t레벨: " << (*monster).level << endl << "HP:" << (*monster).Hp << endl;
        cout << "===스킬 목록===" << endl;
        for (int i = 0; i < P_Slot_Max; i++)
            cout << i << ". " << (**player).skill_sloat[i].Name << endl;
        cout << "4. 일반공격" << endl;
        cout << "선택: "; cin >> Choice;

        if (cin.fail())//잘못 입력시 되돌리는 기능
        {
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }
        int P_Damage = (*monster).Defence - (**player).Attack;
        int P_Armor = (**player).Defence - (*monster).Attack;
        switch (Choice)
        {

        case Slot_1 + 1:
        {
            switch ((**player).skill_sloat[Slot_1].Type)
            {
            case Skill_type_Damage:
            {
                P_Damage -= (**player).skill_sloat[Slot_1].Damage;
            }
                break;
            case Skill_type_Buff_Armor:
            {
                P_Armor += (**player).skill_sloat[Slot_1].Buff_Armor;
            }
                break;
            case Skill_type_Buff_Attack:
            {
                P_Damage -= (**player).skill_sloat[Slot_1].Buff_Attack;
            }
                break;
            }
            cout << (**player).skill_sloat[Slot_1].Name << endl;
            (*monster).Hp += P_Damage;

        }
        break;
        case Slot_2 + 1:
        {
          
            switch ((**player).skill_sloat[Slot_2].Type)
            {
            case Skill_type_Damage:
            {
                P_Damage -= (**player).skill_sloat[Slot_2].Damage;
            }
            break;
            case Skill_type_Buff_Armor:
            {
                P_Armor += (**player).skill_sloat[Slot_2].Buff_Armor;
            }
            break;
            case Skill_type_Buff_Attack:
            {
                P_Damage -= (**player).skill_sloat[Slot_2].Buff_Attack;
            }
            break;
            }

            cout << (**player).skill_sloat[Slot_2].Name << endl;
            (* monster).Hp += P_Damage;
        }
        break;
        case Slot_3 + 1:
        {

            switch ((**player).skill_sloat[Slot_3].Type)
            {
            case Skill_type_Damage:
            {
                P_Damage -= (**player).skill_sloat[Slot_3].Damage;
            }
            break;
            case Skill_type_Buff_Armor:
            {
                P_Armor += (**player).skill_sloat[Slot_3].Buff_Armor;
            }
            break;
            case Skill_type_Buff_Attack:
            {
                P_Damage -= (**player).skill_sloat[Slot_3].Buff_Attack;
            }
            break;
            }
            cout << (**player).skill_sloat[Slot_3].Name << endl;
            (*monster).Hp += P_Damage;
        }
        break;
        case Slot_Max:
        {

            switch ((**player).skill_sloat[Slot_4].Type)
            {
            case Skill_type_Damage:
            {
                P_Damage -= (**player).skill_sloat[Slot_4].Damage;
            }
            break;
            case Skill_type_Buff_Armor:
            {
                P_Armor += (**player).skill_sloat[Slot_4].Buff_Armor;
            }
            break;
            case Skill_type_Buff_Attack:
            {
                P_Damage -= (**player).skill_sloat[Slot_4].Buff_Attack;
            }
            break;
            }
            cout << "공격!" << endl;
            (*monster).Hp += P_Damage;
        }
        break;
        }

        if ((*monster).Hp <= 0)
        {
            (**player).Gold += (*monster).DropGold;
            (**player).EXP += (*monster).EXP;
            /*레벨업 구현 */
            break;
        }
        else if ((**player).Hp <= 0)
        {
            cout << "사망" << endl;
            (**player).Hp = (**player).Hp_Max;
            (**player).Mp = (**player).Mp_Max;
        }


        system("pause");

    }




}

void Select_job_Inherit_Ability(Player* player)// 직업 선택시 스텟 및 스킬 변경
{
    Job_Warrior warrior;
    Job_Wizard wizard;

    //전사
    strcpy(warrior.Warrior_Skill_List[Slot_1].Name, "스매시");
    strcpy(warrior.Warrior_Skill_List[Slot_1].Decs, "강하게 적을 공격합니다.");
    warrior.Warrior_Skill_List[Slot_1].Damage = 20;
    warrior.Warrior_Skill_List[Slot_1].Mp = 5;
    warrior.Warrior_Skill_List[Slot_1].Type = Skill_type_Damage;

    strcpy(warrior.Warrior_Skill_List[Slot_2].Name, "더블스매시");
    strcpy(warrior.Warrior_Skill_List[Slot_2].Decs, "강하게 적을 두번 공격합니다.");
    warrior.Warrior_Skill_List[Slot_2].Damage = 20*2;
    warrior.Warrior_Skill_List[Slot_2].Mp = 8;
    warrior.Warrior_Skill_List[Slot_2].Type = Skill_type_Damage;

    strcpy(warrior.Warrior_Skill_List[Slot_3].Name, "트리포스");
    strcpy(warrior.Warrior_Skill_List[Slot_3].Decs, "나무처럼 굳건하게 공격을 강화시킵니다.");
    warrior.Warrior_Skill_List[Slot_3].Buff_Attack = 10;
    warrior.Warrior_Skill_List[Slot_3].Damage = 0;
    warrior.Warrior_Skill_List[Slot_3].Mp = 5;
    warrior.Warrior_Skill_List[Slot_3].Type = Skill_type_Buff_Attack;

    strcpy(warrior.Warrior_Skill_List[Slot_4].Name, "갑옷 강화");
    strcpy(warrior.Warrior_Skill_List[Slot_4].Decs, "갑옷을 강화시킵니다.");
    warrior.Warrior_Skill_List[Slot_4].Buff_Armor = 15;
    warrior.Warrior_Skill_List[Slot_4].Mp = 5;
    warrior.Warrior_Skill_List[Slot_4].Damage = 0;
    warrior.Warrior_Skill_List[Slot_4].Type = Skill_type_Buff_Armor;
    //법사
    strcpy(wizard.Wizard_Skill_List[Slot_1].Name, "불공");
    strcpy(wizard.Wizard_Skill_List[Slot_1].Decs, "불속성의 공을 던집니다.");
    wizard.Wizard_Skill_List[Slot_1].Damage = 30;
    wizard.Wizard_Skill_List[Slot_1].Mp = 20;
    wizard.Wizard_Skill_List[Slot_1].Type = Skill_type_Damage;

    strcpy(wizard.Wizard_Skill_List[Slot_2].Name, "얼음공");
    strcpy(wizard.Wizard_Skill_List[Slot_2].Decs, "얼음속성의 공을 던집니다.");
    wizard.Wizard_Skill_List[Slot_2].Damage = 3;
    wizard.Wizard_Skill_List[Slot_2].Mp = 5;
    wizard.Wizard_Skill_List[Slot_2].Debuff_Armor = 17;
    wizard.Wizard_Skill_List[Slot_2].Type = Skill_type_Damage;

    strcpy(wizard.Wizard_Skill_List[Slot_3].Name, "전기공");
    strcpy(wizard.Wizard_Skill_List[Slot_3].Decs, "전기속성의 공을 던집니다.");
    wizard.Wizard_Skill_List[Slot_3].Damage = 15;
    wizard.Wizard_Skill_List[Slot_3].Mp = 10;
    wizard.Wizard_Skill_List[Slot_3].Debuff_Attack = 10;
    wizard.Wizard_Skill_List[Slot_3].Type = Skill_type_Damage;

    strcpy(wizard.Wizard_Skill_List[Slot_4].Name, "엘리멘탈 볼");
    strcpy(wizard.Wizard_Skill_List[Slot_4].Decs, "다속성의 공을 던집니다.");
    wizard.Wizard_Skill_List[Slot_4].Damage = 20;
    wizard.Wizard_Skill_List[Slot_4].Mp = 100;
    wizard.Wizard_Skill_List[Slot_4].Debuff_Armor = 17;
    wizard.Wizard_Skill_List[Slot_4].Debuff_Attack = 10;
    wizard.Wizard_Skill_List[Slot_4].Type = Skill_type_Damage;
 
    switch (Choice)
    {
    case Warrior:
    {
        player->job = Warrior;
        player->Attack = warrior.Attack_start;
        player->Defence = warrior.Defence_start;
        player->Hp = warrior.Hp_start;
        player->Mp = warrior.Mp_start;
        player->Hp_Max = warrior.Hp_Max_start;
        player->Mp_Max = warrior.Mp_Max_start;
        player->Hp_growth = warrior.Hp_growth;
        player->Mp_growth = warrior.Mp_growth;
        player->Hp_Max_growth = warrior.Hp_Max_growth;
        player->Mp_Max_growth = warrior.Mp_Max_growth;
        player->Attack_growth = warrior.Attack_growth;
        player->Defence_growth = warrior.Defence_growth;

        for (int i = 0; i < Slot_Max; i++)
        {
            player->skill_Learn_list[i] = warrior.Warrior_Skill_List[i];
        }
    }
        break;
    case Wizard:
    {
        player->job = Wizard;
        player->Attack = wizard.Attack_start;
        player->Defence = wizard.Defence_start;
        player->Hp = wizard.Hp_start;
        player->Mp = wizard.Mp_start;
        player->Hp_Max = wizard.Hp_Max_start;
        player->Mp_Max = wizard.Mp_Max_start;
        player->Hp_growth = wizard.Hp_growth;
        player->Mp_growth = wizard.Mp_growth;
        player->Hp_Max_growth = wizard.Hp_Max_growth;
        player->Mp_Max_growth = wizard.Mp_Max_growth;
        player->Attack_growth = wizard.Attack_growth;
        player->Defence_growth = wizard.Defence_growth;

        for (int i = 0; i < Slot_Max; i++)
        {
            player->skill_Learn_list[i] = wizard.Wizard_Skill_List[i];
        }
    }
        break;
    }
}

void Monster_List_Add()
{
    strcpy(Monster_List[Mouse].Name, "쥐");
    Monster_List[Mouse].Attack = 5;
    Monster_List[Mouse].Defence = 7;
    Monster_List[Mouse].Hp = 100;
    Monster_List[Mouse].DropGold = 100;
    Monster_List[Mouse].EXP = 30;
    Monster_List[Mouse].level = 1;
    Monster_List[Mouse].Hp_growth = 10;

    strcpy(Monster_List[WildBoar].Name, "멧돼지");
    Monster_List[WildBoar].Attack = 20;
    Monster_List[WildBoar].Defence = 10;
    Monster_List[WildBoar].Hp = 300;
    Monster_List[WildBoar].DropGold = 1000;
    Monster_List[WildBoar].EXP = 100;
    Monster_List[WildBoar].level = 3;
    Monster_List[WildBoar].Hp_growth = 10;

    strcpy(Monster_List[Orc].Name, "오크");
    Monster_List[Orc].Attack = 50;
    Monster_List[Orc].Defence = 50;
    Monster_List[Orc].Hp = 500;
    Monster_List[Orc].DropGold = 20000;
    Monster_List[Orc].EXP = 1000;
    Monster_List[Orc].level = 10;
    Monster_List[Orc].Hp_growth = 10;

    strcpy(Monster_List[Dragon].Name, "드래곤");
    Monster_List[Dragon].Attack = 70;
    Monster_List[Dragon].Defence = 70;
    Monster_List[Dragon].Hp = 1000;
    Monster_List[Dragon].DropGold = 80000;
    Monster_List[Dragon].EXP = 10000;
    Monster_List[Dragon].level = 13;
    Monster_List[Dragon].Hp_growth = 10;
  
}


// 스킬 버프 디버프 구분시키기 (스킬 구현 다시하기) 