package com.product_info.controller;

import jakarta.servlet.RequestDispatcher;
import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import java.io.IOException;

/**
 * Servlet implementation class FrontControllerServlet
 */
@WebServlet("/")
public class FrontControllerServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse
	 *      response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {

		String path = request.getServletPath();
		String outcome = null;

		switch (path) {
		case "/":
			outcome = "/home";
			break;

		case "/products":
			outcome = "/products-processor";
			break;

		default:
			outcome = "/home";
			break;
		}
		RequestDispatcher rd = request.getRequestDispatcher(outcome);
		rd.forward(request, response);
	}


}
