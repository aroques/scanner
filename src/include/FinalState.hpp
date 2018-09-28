/*
    These are states that are stored in the FSA table.
    We have states 5 states, so start counting at 5.
*/

enum FinalState
{
    ERROR = 5,
    OPERATOR_DELIMITER_TK,
    IDENTIFIER_TK,
    NUMBER_TK,
    END_OF_FILE_TK
};