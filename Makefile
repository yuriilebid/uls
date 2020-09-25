NAME	=	uls

CFLG	=	-std=c11 $(addprefix -W, all extra error pedantic) -g

SRCD	=	src
INCD	=	inc
OBJD	=	obj

LMXD	=	libmx
LMXA:=	$(LMXD)/libmx.a
LMXI:=	$(LMXD)/$(INCD)

INC		=	uls.h
INCS	=	$(addprefix $(INCD)/, $(INC))

SRC		=	main.c\
		mx_a_checker.c\
		mx_argv_index.c\
		mx_convert_date.c\
		mx_count_list.c\
		mx_create_tdirs.c\
		mx_create_tfiles.c\
		mx_directories.c\
		mx_each_l_add.c\
		mx_error.c\
		mx_error_printer.c\
		mx_file_exists.c\
		mx_file_mode.c\
		mx_file_mode_add.c\
		mx_file_name_retriever.c\
		mx_file_type.c\
		mx_files_list_maker.c\
		mx_files_printer.c\
		mx_flag_G.c\
		mx_flag_d.c\
		mx_flag_l_out_add.c\
		mx_flag_l_output.c\
		mx_flag_m.c\
		mx_flag_p.c\
		mx_flag_p_for_pureoutput.c\
		mx_flags_parser.c\
		mx_free_strarr.c\
		mx_getUser.c\
		mx_get_size.c\
		mx_get_size_if.c\
		mx_get_stgid.c\
		mx_high_minor.c\
		mx_is_directory.c\
		mx_itoas_addition.c\
		mx_list_of_dirs.c\
		mx_list_of_files.c\
		mx_longest_devs.c\
		mx_minus_one.c\
		mx_newline.c\
		mx_permission_denied.c\
		mx_print_total.c\
		mx_pure_addition.c\
		mx_pure_output.c\
		mx_push_back_tdirs.c\
		mx_push_back_tfiles.c\
		mx_recursion.c\
		mx_rest.c\
		mx_return_value.c\
		mx_second_section.c\
		mx_sort_output.c\
		mx_specified_directories.c\
		mx_super_print.c\
		mx_tfiles_freesher.c\
		mx_type.c\


SRCS	=	$(addprefix $(SRCD)/, $(SRC))
OBJS	=	$(addprefix $(OBJD)/, $(SRC:%.c=%.o))

all: $(LMXD) $(NAME)

$(FILE:a/%=%)

#install: $(LMXA) $(NAME)

$(NAME): $(LMXA) $(OBJS)
	@clang $(CFLG) $(OBJS) -L$(LMXD) -lmx -o $@
	@printf "\r\33[2K$@ \033[32;1mcreated\033[0m\n"

$(OBJD)/%.o: $(SRCD)/%.c $(INCS)
	@clang $(CFLG) -c $< -o $@ -I$(INCD) -I$(LMXI)
	@printf "\r\33[2K$(NAME) \033[33;1mcompile \033[0m$(<:$(SRCD)/%.c=%) "

$(OBJS): | $(OBJD)

$(OBJD):
	@mkdir -p $@

$(LMXD): $(LMXA)

$(LMXA):
	@make -sC $(LMXD)

clean:
	@make -sC $(LMXD) $@
	@rm -rf $(OBJD)
	@printf "$(OBJD)\t   \033[31;1mdeleted\033[0m\n"

uninstall: clean
	@make -sC $(LMXD) $@
	@rm -rf $(NAME)
	@printf "$(NAME) \033[31;1muninstalled\033[0m\n"

reinstall: uninstall all