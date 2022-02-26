#include"Make_static.h"

void Make_static::set_loan_id_maker(int l){
    loan_id_maker = l;
}
int Make_static::get_loan_id_maker(){
    loan_id_maker++;
    return loan_id_maker;
}
