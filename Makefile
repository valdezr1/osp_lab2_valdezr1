new_cat:
	gcc -o new_cat_exec new_cat.c
new_echo:
	gcc -o new_echo_exec new_echo.c
new_tail:
	gcc -o new_tail_exec new_tail.c
new_wc:
	gcc -o new_wc_exec new_wc.c
all:
	gcc -o new_cat_exec new_cat.c
	gcc -o new_echo_exec new_echo.c
	gcc -o new_tail_exec new_tail.c
	gcc -o new_wc_exec new_wc.c
clean:
	rm -f new_cat_exec new_echo_exec new_tail_exec new_wc_exec
