package com.product_info.dao;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.util.ArrayList;
import java.util.List;

import com.product_info.entities.Category;
import com.product_info.utils.DBUtils;

public class CategoryDaoImpl implements CategoryDao {

	@Override
	public List<Category> getAllCategories() {
		List<Category> categories = new ArrayList<>();
		String query = "SELECT category_id, category_name, description FROM categories ORDER BY category_id ASC";

		try (Connection conn = DBUtils.getConnection();
				PreparedStatement stmt = conn.prepareStatement(query);
				ResultSet rs = stmt.executeQuery()) {

			while (rs.next()) {
				categories.add(new Category(rs.getInt("category_id"), rs.getString("category_name"),
						rs.getString("description")));
			}
		} catch (Exception e) {
			e.printStackTrace();
		}
		return categories;
	}

}
