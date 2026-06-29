package com.product_info.controller;

import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.util.List;

import com.product_info.dao.CategoryDao;
import com.product_info.dao.ProductDao;
import com.product_info.dao.ProductDaoImpl;
import com.product_info.entities.Product;

/**
 * Servlet implementation class ProductServlet
 */
@WebServlet("/products-processor")
public class ProductServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
	private ProductDao productDao;

	protected void doGet(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		productDao = new ProductDaoImpl();
		String id = request.getParameter("categoryId");

		if (id == null || id.trim().isEmpty()) {
			response.sendRedirect(request.getContextPath() + "/");
			return;
		}

		int cId = Integer.parseInt(id);
		List<Product> products = productDao.getProductsByCategory(cId);
		request.setAttribute("products", products);
		request.getRequestDispatcher("/WEB-INF/views/products.jsp").forward(request, response);

	}

}
