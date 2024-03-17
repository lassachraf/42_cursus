/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achraf <achraf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 21:19:24 by achraf            #+#    #+#             */
/*   Updated: 2024/03/17 01:58:47 by achraf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*safe_malloc(size_t bytes)
{
	void	*ret;

	ret = malloc(bytes);
	if (!ret)
		return (NULL);
	return (ret);
}

void	safe_mutex(pthread_mutex_t *mutex, int flag)
{
	if (flag == 0)
		pthread_mutex_init(mutex, NULL);
	else if (flag == 1)
		pthread_mutex_lock(mutex);
	else if (flag == 2)
		pthread_mutex_unlock(mutex);
	else if (flag == 3)
		pthread_mutex_destroy(mutex);
}

// void	handle_mutex(int status, char *flag)
// {
// 	if (0 == status)
// 		return ;
// 	if (EINVAL == status && ("LOCK" == flag || "UNLOCK" == flag))
// 		ft_error("The value specified by mutex is invalid !\n");
// 	else if (EINVAL == status && "INIT" == flag)
// 		ft_error("The value specified by attr is invalid !\n");
// 	else if (EDEADLK == status)
// 		ft_error("A deadlock would occur if the thread "
// 			"blocked waiting for mutex.");
// 	else if (EPERM == status)
// 		ft_error("The current thread does not hold a lock on mutex.");
// 	else if (ENOMEM == status)
// 		ft_error("The process cannot allocate enough memory"
// 			" to create another mutex.");
// 	else if (EBUSY == status)
// 		ft_error("Mutex is locked");
// }

// void    safe_thread(pthread_mutex_t *mutex, int flag)
// {
//     if (flag == 0)
// 		pthread_mutex_init(mutex, NULL);
// 	else if (flag == 1)
// 		pthread_mutex_lock(mutex);
// 	else if (flag == 2)
// 		pthread_mutex_unlock(mutex);
// 	else if (flag == 3)
// 		pthread_mutex_destroy(mutex);
// }