#include <iostream>
#include <vector>
#include <string>
using namespace std;

// HackerRank
class Spell { 
    private:
        string scrollName;
    public:
        Spell(): scrollName("") { }
        Spell(string name): scrollName(name) { }
        virtual ~Spell() { }
        string revealScrollName() {
            return scrollName;
        }
};

// HackerRank
class Fireball : public Spell { 
    private: int power;
    public:
        Fireball(int power): power(power) { }
        void revealFirepower(){
            cout << "Fireball: " << power << endl;
        }
};

// HackerRank
class Frostbite : public Spell {
    private: int power;
    public:
        Frostbite(int power): power(power) { }
        void revealFrostpower(){
            cout << "Frostbite: " << power << endl;
        }
};

// HackerRank
class Thunderstorm : public Spell { 
    private: int power;
    public:
        Thunderstorm(int power): power(power) { }
        void revealThunderpower(){
            cout << "Thunderstorm: " << power << endl;
        }
};

// HackerRank
class Waterbolt : public Spell { 
    private: int power;
    public:
        Waterbolt(int power): power(power) { }
        void revealWaterpower(){
            cout << "Waterbolt: " << power << endl;
        }
};

// HackerRank
class SpellJournal {
    public:
        static string journal;
        static string read() {
            return journal;
        }
}; 
string SpellJournal::journal = "";

// Solution
// Use dynamic cast to determine what type of spell was passed in
void counterspell(Spell *spell) {
    // Attempt to cast Spell* spell to Fireball*
    // Returns a Fireball* if successful, NULL otherwise
    if(dynamic_cast<Fireball*>(spell) != NULL) {
        Fireball* fireSpell = dynamic_cast<Fireball*>(spell);
        fireSpell->revealFirepower();
    }
    else if(dynamic_cast<Frostbite*>(spell) != NULL) {
        Frostbite* frostSpell = dynamic_cast<Frostbite*>(spell);
        frostSpell->revealFrostpower();
    }
    else if(dynamic_cast<Thunderstorm*>(spell) != NULL) {
        Thunderstorm* thunderSpell = dynamic_cast<Thunderstorm*>(spell);
        thunderSpell->revealThunderpower();
    }
    else if(dynamic_cast<Waterbolt*>(spell) != NULL) {
        Waterbolt* waterSpell = dynamic_cast<Waterbolt*>(spell);
        waterSpell->revealWaterpower();
    }
    else {
        string journal = SpellJournal::read();
        string spellName = spell->revealScrollName();
        // find longest common subsequence of journal and spellName
        string lcs = "";
        int a = journal.length();
        int b = spellName.length();
        // dynamic programming table
        // with space for padding 0s in top row, left column
        int dp_table[a+1][b+1];
        // manually initialize to all 0s
        for(int i = 0; i <= a; ++i) {
            for(int j = 0; j <= b; ++j) {
                dp_table[i][j] = 0;
            }
        }
        // dynamic programming solution
        for(int i = 1; i <= a; ++i) {
            for(int j = 1; j <= b; ++j) {
                // convert 1-based index to 0-based for strings
                if(journal[i-1] == spellName[j-1]) {
                    // fill table with table entry for subproblem
                    // with last character removed + 1
                    dp_table[i][j] = 1 + dp_table[i-1][j-1];
                }
                else {
                    // fill table with max of subproblem
                    // from removing a character from either journal or spellName
                    dp_table[i][j] = max(dp_table[i-1][j], dp_table[i][j-1]);
                }
            }
        }
        int lcs_length = dp_table[a][b];
        cout << lcs_length << '\n';
    }
}

class Wizard {
    public:
        Spell *cast() {
            Spell *spell;
            string s; cin >> s;
            int power; cin >> power;
            if(s == "fire") {
                spell = new Fireball(power);
            }
            else if(s == "frost") {
                spell = new Frostbite(power);
            }
            else if(s == "water") {
                spell = new Waterbolt(power);
            }
            else if(s == "thunder") {
                spell = new Thunderstorm(power);
            } 
            else {
                spell = new Spell(s);
                cin >> SpellJournal::journal;
            }
            return spell;
        }
};

int main() {
    int T;
    cin >> T;
    Wizard Arawn;
    while(T--) {
        Spell *spell = Arawn.cast();
        counterspell(spell);
    }
    return 0;
}