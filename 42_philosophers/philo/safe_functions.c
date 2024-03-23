/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achraf <achraf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 21:19:24 by achraf            #+#    #+#             */
/*   Updated: 2024/03/23 03:39:07 by achraf           ###   ########.fr       */
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
// 					"blocked waiting for mutex.");
// 	else if (EPERM == status)
// 		ft_error("The current thread does not hold a lock on mutex.");
// 	else if (ENOMEM == status)
// 		ft_error("The process cannot allocate enough memory"
// 					" to create another mutex.");
// 	else if (EBUSY == status)
// 		ft_error("Mutex is locked");
// }

void	thread_error(int status, int flag)
{
	if (status == 0)
		return ;
	if (status == EAGAIN)
		ft_error("No resources to create another thread");
	else if (status == EPERM)
		ft_error("The caller does not have appropriate permission\n");
	else if (status == EINVAL && flag == 0)
		ft_error("The value specified by attr is invalid.");
	else if (status == EINVAL && (flag == 1 || flag == 2))
		ft_error("The value specified by thread is not joinable\n");
	else if (status == ESRCH)
		ft_error("No thread could be found corresponding to that"
			"specified by the given thread ID, thread.\n");
	else if (status == EDEADLK)
		ft_error("A deadlock was detected or the value of"
			"thread specifies the calling thread.\n");
}

void	safe_thread(pthread_t *thread, void *(*func)(void *), void *arg,
		int flag)
{
	if (flag == 0)
		thread_error(pthread_create(thread, NULL, func, arg), flag);
	else if (flag == 1)
		thread_error(pthread_join(*thread, NULL), flag);
	else if (flag == 2)
		thread_error(pthread_detach(*thread), flag);
}