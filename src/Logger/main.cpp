/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlonka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 12:55:01 by nlonka            #+#    #+#             */
/*   Updated: 2024/04/16 13:35:47 by nlonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Logger.hpp"

int main()
{
	Logger::initLogger();
	Logger::log(INFO, CLIENT, "%s disconnected", "mutsis");
	

	return 0;
}
