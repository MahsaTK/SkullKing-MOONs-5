#include <functions.h>

void switch_card(Player first, Player second) {
    first.cards.push_back(second.cards.front());
    second.cards.push_back(first.cards.front());
    first.cards.pop_front();
    second.cards.pop_front();
}
QTextStream& operator<<(QTextStream &out,GameInfo& g){
    for(int i=0;i<7;i++){
        out <<QString::number(g.predict1[i])<<'\n'
            <<QString::number(g.predict2[i])<<'\n'
            <<QString::number(g.result1[i])<<'\n'
            <<QString::number(g.result2[i])<<'\n';
    }
    for(int i=0;i<3;i++){
        out <<QString::number(g.character1[i])<<'\n'
            <<QString::number(g.character2[i])<<'\n';
    }
    return out;
}
QTextStream& operator>>(QTextStream &in,GameInfo& g){
    for(int i=0;i<7;i++){
        g.predict1[i]=in.readLine().toInt();
        g.predict2[i]=in.readLine().toInt();
        g.result1[i]=in.readLine().toInt();
        g.result2[i]=in.readLine().toInt();
    }
    for(int i=0;i<3;i++){
        g.character1[i]=in.readLine().toInt();
        g.character2[i]=in.readLine().toInt();
    }
    return in;
}
QTextStream& operator<<(QTextStream &out,Player& c){
    out<< QString::fromStdString(c.name)<<'\n'
        <<QString::fromStdString(c.last_name)<<'\n'
        <<QString::fromStdString(c.username)<<'\n'
        <<QString::fromStdString(c.address)<<'\n'
        <<QString::fromStdString(c.phone_number)<<'\n'
        <<QString::fromStdString(c.password)<<'\n'
        <<QString::fromStdString(c.email)<<'\n'
        <<QString::number(c.won)<<'\n'
        <<QString::number(c.lost)<<'\n'
        <<QString::number(c.coins)<<'\n';
    return out;
}
QTextStream& operator>>(QTextStream &in,Player& c){
    c.name=in.readLine().toStdString();
    c.last_name=in.readLine().toStdString();
    c.username=in.readLine().toStdString();
    c.address=in.readLine().toStdString();
    c.phone_number=in.readLine().toStdString();
    c.password=in.readLine().toStdString();
    c.email=in.readLine().toStdString();
    c.won=in.readLine().toInt();
    c.lost=in.readLine().toInt();
    c.coins=in.readLine().toInt();
    return in;
}

void READ_FILE(vector<Player> &users){
    if(!users.empty()){return;}
    QString projectDir = QCoreApplication::applicationDirPath();
    QFile file(projectDir+"/"+"Player_Info.txt");
    if (!file.open(QIODevice::ReadOnly))
        return;

    QTextStream in(&file);
    while( !in.atEnd()){
        Player player;
        in>>player;
        in>>player.last_game;
        users.push_back(player);
    }
    file.close();
}
void WRITE_FILE(vector<Player> &users){
    QString projectDir = QCoreApplication::applicationDirPath();
    QFile file(projectDir+"/"+"Player_Info.txt");
    if (!file.open(QIODevice::WriteOnly))
        return;
    QTextStream out(&file);
    for(auto &c :users){
        out << c
            <<c.last_game;
    }
    file.close();
}
