package com.product_info.dao;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.util.ArrayList;
import java.util.List;

import com.product_info.entities.Product;
import com.product_info.utils.DBUtils;

public class ProductDaoImpl implements ProductDao {
	@Override
	public List<Product> getProductsByCategory(int categoryId) {
		List<Product> products = new ArrayList<>();

		String query = "SELECT  product_id ,product_name , price , stock , category_id FROM Products where category_id = ? ORDER BY product_name ASC";

		try (Connection conn = DBUtils.getConnection(); PreparedStatement stmt = conn.prepareStatement(query);) {
			stmt.setInt(1, categoryId);
			ResultSet rs = stmt.executeQuery();
			while (rs.next()) {
				products.add(new Product(rs.getInt("product_id"), rs.getString("product_name"), rs.getDouble("price"),
						rs.getDouble("stock"), rs.getInt("category_id")));
			}
		} catch (Exception e) {
			e.printStackTrace();
		}
		return products;
	}
}
