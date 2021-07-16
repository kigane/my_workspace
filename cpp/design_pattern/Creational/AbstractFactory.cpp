#include <iostream>
using namespace std;

#define PRINT(x) cout << x << endl;

enum class Direction
{
    East, North, West, South
};

class Maze
{
public:
    void AddRoom(Room* r) {}
    Room* RoomNo(int num) const {}
};

class MapSite
{
public:
    virtual void Enter() = 0;
};

class Room : public MapSite
{
public:
    Room(int num);

    MapSite* GetSide(Direction d) {}
    void SetSide(Direction d, MapSite* m) {}

    virtual void Enter() override {}
private:
    MapSite* m_Sides[4];
    int m_RoomNumber;
};

class Wall : public MapSite
{
public:
    Wall();
    virtual void Enter() override {}
};

class Door : public MapSite
{
public:
    Door(Room* r1 = nullptr, Room* r2 = nullptr);
    virtual void Enter() override {}
    Room* OtherSideFrom(Room* r);
private:
    Room* m_Room1;
    Room* m_Room2;
    bool m_IsOpen;
};

class MazeGame
{
public:
    MazeGame();
    Maze* CreateMaze() 
    {
        Maze* aMaze = new Maze();
        Room* r1 = new Room(1);
        Room* r2 = new Room(2);
        Door* theDoor = new Door(r1, r2);

        aMaze->AddRoom(r1);
        aMaze->AddRoom(r2);

        r1->SetSide(Direction::North, new Wall);
        r1->SetSide(Direction::East, theDoor);
        r1->SetSide(Direction::South, new Wall);
        r1->SetSide(Direction::West, new Wall);

        r2->SetSide(Direction::North, new Wall);
        r2->SetSide(Direction::East, new Wall);
        r2->SetSide(Direction::South, new Wall);
        r2->SetSide(Direction::West, theDoor);

        return aMaze;
    }
};

class MazeFactory
{
public:
    MazeFactory();
    virtual Maze* MakeMaze() const { return new Maze(); }
    virtual Wall* MakeWall() const { return new Wall(); }
    virtual Room* MakeRoom() const { return new Room(1); }
    virtual Door *MakeDoor(Room r1, Room r2) const { return new Door(new Room(1), new Room(2)); }

};

int main(){
    
}