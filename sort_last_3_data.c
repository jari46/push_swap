/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_last_3_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehan <yehan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 11:15:01 by yehan             #+#    #+#             */
/*   Updated: 2022/06/30 11:15:02 by yehan            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_last_3_data(t_pushswap *pushswap)
{
	t_data	d1;
	t_data	d2;
	t_data	d3;

	d1 = pushswap->stack_b->tail->next->data;
	d2 = pushswap->stack_b->tail->next->next->data;
	d3 = pushswap->stack_b->tail->next->next->next->data;
	if (d1 < d2 && d2 < d3 && d1 < d3)
		sort_123(pushswap);
	else if (d1 < d2 && d2 > d3 && d1 < d3)
		sort_132(pushswap);
	else if (d1 > d2 && d2 < d3 && d1 < d3)
		sort_213(pushswap);
	else if (d1 < d2 && d2 > d3 && d1 > d3)
		sort_231(pushswap);
	else if (d1 > d2 && d2 < d3 && d1 > d3)
		sort_312(pushswap);
}
