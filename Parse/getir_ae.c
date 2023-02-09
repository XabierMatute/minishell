/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getir_ae.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 17:52:43 by xmatute-          #+#    #+#             */
/*   Updated: 2023/02/07 17:26:35 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static unsigned int	redirections(char *s)
{
	unsigned int	p;

	p = 0;
	while (*(s))
	{
		s = ignoreq(s);
		if (s[0] == '<' && s[1] == '<')
			p++;
		if (*s)
			s++;
	}
	return (p);
}



char	**getir_ae(char *s)
{
	char	**ir;
	size_t	i;

	ir = ft_calloc(redirections(s) + 1, sizeof(char *));
	i = 0;
	while (*s)
	{
		s = ignoreq(s);
		if (s[0] == '<' && s[1] == '<')
		{
			ir[i] = extract(s + 2);
			s[0] = ' ';
			s[1] = ' ';
			i++;
		}
		s++;
	}
	ir[i] = 0;
	return(ir);
}

// void	doubleprint(char **ss)
// {
// 	while (*ss)
// 	{
// 		ft_printf("%s\n", *ss);
// 		ss++;
// 	}
// }

// int main(int argc, char const *argv[])
// {
// 	char *s;
// 	char **ora;
// 	char **ira;
// 	char **ir;
// 	char **or;

// 	s = ft_strdup("");
// 	ft_printf("\nantes  :%s\n", s);

// 	ira = getir_ae(s);
// 	ora = getor_ae(s);
// 	ir = getir(s);
// 	or = getor(s);
// 	ft_printf("despues:%s\n", s);
// 	ft_printf("<<\n");
// 	doubleprint(ira);
// 	ft_printf("<\n");
// 	doubleprint(ir);
// 	ft_printf(">>\n");
// 	doubleprint(ora);
// 	ft_printf(">\n");
// 	doubleprint(or);

// 	s = ft_strdup("ey");
// 	ft_printf("\nantes  :%s\n", s);

// 	ira = getir_ae(s);
// 	ora = getor_ae(s);
// 	ir = getir(s);
// 	or = getor(s);
// 	ft_printf("despues:%s\n", s);
// 	ft_printf("<<\n");
// 	doubleprint(ira);
// 	ft_printf("<\n");
// 	doubleprint(ir);
// 	ft_printf(">>\n");
// 	doubleprint(ora);
// 	ft_printf(">\n");
// 	doubleprint(or);

// 	s = ft_strdup("echo hola bebe > saludo << file < otrofile");
// 	ft_printf("\nantes  :%s\n", s);

// 	ira = getir_ae(s);
// 	ora = getor_ae(s);
// 	ir = getir(s);
// 	or = getor(s);
// 	ft_printf("despues:%s\n", s);
// 	ft_printf("<<\n");
// 	doubleprint(ira);
// 	ft_printf("<\n");
// 	doubleprint(ir);
// 	ft_printf(">>\n");
// 	doubleprint(ora);
// 	ft_printf(">\n");
// 	doubleprint(or);


// 			s = ft_strdup("echo<redir hola bebe > saludo<despedida << file uwu");
// 	ft_printf("\nantes  :%s\n", s);

// 	ira = getir_ae(s);
// 	ora = getor_ae(s);
// 	ir = getir(s);
// 	or = getor(s);
// 	ft_printf("despues:%s\n", s);
// 	ft_printf("<<\n");
// 	doubleprint(ira);
// 	ft_printf("<\n");
// 	doubleprint(ir);
// 	ft_printf(">>\n");
// 	doubleprint(ora);
// 	ft_printf(">\n");
// 	doubleprint(or);

// 				s = ft_strdup("echo  <<Rchivp hola bebe > saludo << file uwu");
// 	ft_printf("\nantes  :%s\n", s);

// 	ira = getir_ae(s);
// 	ora = getor_ae(s);
// 	ir = getir(s);
// 	or = getor(s);
// 	ft_printf("despues:%s\n", s);
// 	ft_printf("<<\n");
// 	doubleprint(ira);
// 	ft_printf("<\n");
// 	doubleprint(ir);
// 	ft_printf(">>\n");
// 	doubleprint(ora);
// 	ft_printf(">\n");
// 	doubleprint(or);

// 				s = ft_strdup("echo hola bebe<<Rchivp> saludo << file uwu");
// 	ft_printf("\nantes  :%s\n", s);

// 	ira = getir_ae(s);
// 	ora = getor_ae(s);
// 	ir = getir(s);
// 	or = getor(s);
// 	ft_printf("despues:%s\n", s);
// 	ft_printf("<<\n");
// 	doubleprint(ira);
// 	ft_printf("<\n");
// 	doubleprint(ir);
// 	ft_printf(">>\n");
// 	doubleprint(ora);
// 	ft_printf(">\n");
// 	doubleprint(or);


// 	s = ft_strdup("echo hola bebe<<\"Rchivp> saludo \"<< file uwu");
// 	ft_printf("\nantes  :%s\n", s);

// 	ira = getir_ae(s);
// 	ora = getor_ae(s);
// 	ir = getir(s);
// 	or = getor(s);
// 	ft_printf("despues:%s\n", s);
// 	ft_printf("<<\n");
// 	doubleprint(ira);
// 	ft_printf("<\n");
// 	doubleprint(ir);
// 	ft_printf(">>\n");
// 	doubleprint(ora);
// 	ft_printf(">\n");
// 	doubleprint(or);

// 	s = ft_strdup("echo hola bebe<<\"Rchivp> saludo \"<< file uwu <<\'<3\'");
// 	ft_printf("\nantes  :%s\n", s);

// 	ira = getir_ae(s);
// 	ora = getor_ae(s);
// 	ir = getir(s);
// 	or = getor(s);
// 	ft_printf("despues:%s\n", s);
// 	ft_printf("<<\n");
// 	doubleprint(ira);
// 	ft_printf("<\n");
// 	doubleprint(ir);
// 	ft_printf(">>\n");
// 	doubleprint(ora);
// 	ft_printf(">\n");
// 	doubleprint(or);

// 	s = ft_strdup("comando>or>otheror >\"otra redirección de output\"> \"otra mas redirección de output\"<ir nomeborres >>atend > \'or <3\'");
// 	ft_printf("\nantes:::%s\n", s);

// 	ira = getir_ae(s);
// 	ora = getor_ae(s);
// 	ir = getir(s);
// 	or = getor(s);
// 	ft_printf("despues:%s\n", s);
// 	ft_printf("<<\n");
// 	doubleprint(ira);
// 	ft_printf("<\n");
// 	doubleprint(ir);
// 	ft_printf(">>\n");
// 	doubleprint(ora);
// 	ft_printf(">\n");
// 	doubleprint(or);

// 	s = ft_strdup("comando>or>otheror >\"otra redireccion de output\"> \"otra mas redireccion de output\"<ir nomeborres >>atend > \'or <3\'hola<<porseaca<<caso");
// 	ft_printf("\nantes  :%s\n", s);

// 	ira = getir_ae(s);
// 	ora = getor_ae(s);
// 	ir = getir(s);
// 	or = getor(s);
// 	ft_printf("despues:%s\n", s);
// 	ft_printf("<<\n");
// 	doubleprint(ira);
// 	ft_printf("<\n");
// 	doubleprint(ir);
// 	ft_printf(">>\n");
// 	doubleprint(ora);
// 	ft_printf(">\n");
// 	doubleprint(or);

// 	s = ft_strdup("hola << q    >>tal mal");
// 	ft_printf("\nantes  :%s\n", s);

// 	ira = getir_ae(s);
// 	ora = getor_ae(s);
// 	ir = getir(s);
// 	or = getor(s);
// 	ft_printf("despues:%s\n", s);
// 	ft_printf("<<\n");
// 	doubleprint(ira);
// 	ft_printf("<\n");
// 	doubleprint(ir);
// 	ft_printf(">>\n");
// 	doubleprint(ora);
// 	ft_printf(">\n");
// 	doubleprint(or);
// 	return 0;
// }