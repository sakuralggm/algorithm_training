// #define LOCAL
#ifdef LOCAL
#define dbg(...) fprintf(stderr, __VA_ARGS__)
#define debug(x) cerr << #x << ' ' <<  '=' << ' ' << x << endl
#else
#define dbg(...)
#define debug(x)
#define NDEBUG
#endif

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

struct Slave
{
    int health, atk;
    bool die;
    Slave(int _h, int _a): health(_h), atk(_a), die(false) {}
    Slave(): health(), atk(), die(false) {}

    void defend(Slave & attacker)
    {
        health -= attacker.atk;
        if (health <= 0) die = true;
    }
    void attack(Slave & defender)
    {
        health -= defender.atk;
        if (health <= 0) die = true;
    }

};
struct Hero
{
    int health, atk;
    bool win;
    vector<Slave> slaves;

    Hero(): health(30), atk(0), win(false) {}
    
    void summon(int pos, int h, int a)
    {
        Slave add(h, a);
        slaves.insert(slaves.begin() + pos - 1, add);
    }
    void defend(Hero & oppo, int atkpos, int atkedpos)
    {
        atkedpos -- , atkpos -- ;
        Slave & attacker = oppo.slaves[atkpos];
        if (atkedpos == -1)
        {
            health -= attacker.atk;
            die(oppo);
        }
        else 
        {
            Slave & defender = slaves[atkedpos];
            defender.defend(attacker);
            attacker.attack(defender);
            if (defender.die) slaves.erase(slaves.begin() + atkedpos);
            if (attacker.die) oppo.slaves.erase(oppo.slaves.begin() + atkpos);
        }
    }
    void die(Hero & oppo)
    {
        if (health > 0) return;
        else
        {
            win = false;
            oppo.win = true;
        }
    }
};
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int n;
    cin >> n;
    Hero heros[2];
    int turn = 0;
    while (n -- )
    {
        string op;
        cin >> op;
        if (op == "end")
        {
            turn = !turn;
            continue;
        }
        Hero & actor = heros[turn];
        if (op == "summon")
        {
            int pos, a, h;
            cin >> pos >> a >> h;
            actor.summon(pos, h, a);
        }
        else 
        {
            int attacker, defender;
            cin >> attacker >> defender;
            heros[!turn].defend(actor, attacker, defender); // actor攻击，另一个防守
        }
    }
    if (heros[0].win) cout << 1 << "\n";
    else if (heros[1].win) cout << -1 << "\n";
    else cout << 0 << "\n";

    for (int i = 0; i < 2; i ++ )
    {
        cout << heros[i].health << "\n";
        cout << heros[i].slaves.size() << ' ';
        for (auto s : heros[i].slaves) cout << s.health << ' ';
        cout << "\n";
    }
    return 0;
}
