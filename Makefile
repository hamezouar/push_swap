# varaibels
NAME        = push_swap
BNAME		= checker
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g
RM          = rm -f

M_SRCS		=	push_swap.c  ft_substr.c ft_sort_index.c ft_swap_five.c ft_sizenode.c ft_chunkalgo.c ft_swap_three.c\
				ft_push_pa.c ft_rotate_ra.c ft_split.c ft_valid_number.c ft_parsing.c ft_rotate_rra.c ft_swap_sa.c ft_rotate_rb.c\
				ft_rotate_rrb.c ft_atoi.c ft_addback.c ft_push_pb.c ft_is_duplicated.c\
				ft_strjoin.c ft_strdup.c\

B_SRCS 		=	b_checker/checker_bonus.c b_checker/ft_addback_bonus.c b_checker/ft_atoi_bonus.c b_checker/ft_parsing_bonus.c b_checker/ft_push_pa_bonus.c\
				b_checker/ft_push_pb_bonus.c b_checker/ft_rotate_ra_bonus.c b_checker/ft_rotate_rb_bonus.c b_checker/ft_rotate_rr_bonus.c\
				b_checker/ft_rotate_rra_bonus.c b_checker/ft_rotate_rrb_bonus.c b_checker/ft_rotate_rrr_bonus.c b_checker/ft_split_bonus.c b_checker/ft_strdup_bonus.c\
				b_checker/ft_strjoin_bonus.c b_checker/ft_swap_sa_bonus.c b_checker/ft_swap_sb_bonus.c b_checker/ft_swap_ss_bonus.c b_checker/ft_valid_number_bonus.c\
				b_checker/get_line_bonus.c b_checker/get_next_utils_bonus.c b_checker/is_duplicated_bonus.c b_checker/freelist_bonus.c b_checker/ft_strjoin_get_bonus.c\

M_OBJS        = $(M_SRCS:.c=.o)
B_OBJS        = $(B_SRCS:.c=.o)

all: $(NAME)
$(NAME): $(M_OBJS)
	$(CC) $(CFLAGS) $(M_OBJS) -o $(NAME)

bonus: $(BNAME)
$(BNAME): $(B_OBJS) 
	$(CC) $(CFLAGS) $(B_OBJS) -o $(BNAME)

%.o: %.c push_swap.h b_checker/checker_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(M_OBJS)  $(B_OBJS)

fclean: clean
	$(RM) $(NAME) $(BNAME)

re: fclean all bonus

.PHONY: all bonus clean fclean re
