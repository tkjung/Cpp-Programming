// append 함수는 리스트의 맨 뒤에 붙이는 함수
void append(struct item ** ppS, int num);
// del_end 는 함수의 맨 뒤에 있는 항목을 삭제하는 함수.
void del_end(struct item ** ppS );
int main(){
    struct item *pStart = 0;
    int data;
    while (scanf("%d", &data) == 1){
        append(&pStart, data);
    }
    print_all(pStart);    del_end(&pStart);  print_all(pStart);
    // 만일 입력이 1 2 3 였다면
    //  1 --> 2 --> 3  --> END 를 출력할 것이고
    //  1 --> 2 --> END 를 출력하게 된다.
    return 0;
}
