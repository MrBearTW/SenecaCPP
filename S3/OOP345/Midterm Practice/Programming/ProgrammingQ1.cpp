enum class StateType
{
    boolean,
    character,
    number
};

typedef struct
{
    char name[20];
    StateType sType;
    union
    {
        bool stateAsBool;
        char stateAsChar;
        int stateAsNum;
    } sState;
} Switch;