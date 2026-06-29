package com.product_info.controller;

import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.util.List;

import com.product_info.dao.CategoryDao;
import com.product_info.dao.CategoryDaoImpl;
import com.product_info.entities.Category;

/**
 * Servlet implementation class HomeServlet
 */
@WebServlet("/home")
public class HomeServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
	private CategoryDao categoryDao;

	@Override
	protected void doGet(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		categoryDao = new CategoryDaoImpl();
		List<Category> categories = categoryDao.getAllCategories();

		request.setAttribute("categories", categories);
		request.getRequestDispatcher("/WEB-INF/views/home.jsp").forward(request, response);
	}

}
