package com.product_info.dao;

import java.util.List;

import com.product_info.entities.Category;

public interface CategoryDao extends BaseDao<Category> {
	List<Category> getAllCategories();

}
