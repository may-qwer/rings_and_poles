class Stack {
    public: int data = -1;
    public: Stack *next;
    public: Stack *top = this;

    public: void push(int d);

    public: int peek();

    public: bool is_empty();

    public: int get_stack_len();

    public: int pop();

    public: int get_el_by_num(int num);
};