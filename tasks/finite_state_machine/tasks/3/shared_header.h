#pragma once

#include <stdbool.h>
#include <stdlib.h>

typedef enum {
    START = 0,
    // READ,
    CHECK_SYMBOL_FIRST,
    WORDS_IN_COMMENT,
    INCREMENT,
    STATECOUNT,
    END
} StateName;

typedef struct State State;

typedef struct {
    State* pipeline;  // Массив состояний
    StateName cur_state;
    char current_symbol;
    int count_words;
    int step;
} StateMachine;

typedef struct State {
    StateName name;
    StateName (*action)(StateMachine*, char ch);
} State;