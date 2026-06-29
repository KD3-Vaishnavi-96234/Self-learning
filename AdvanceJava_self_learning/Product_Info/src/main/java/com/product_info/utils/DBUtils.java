package com.product_info.utils;

import java.sql.*;

public class DBUtils {
	private final static String dbURL = "jdbc:mysql://localhost:3306/product_list";
	private final static String userName = "root";
	private final static String password = "Vaish@123";
	
	//add static method to return DB connection to the caller
	public static Connection getConnection() throws SQLException
	{
		return DriverManager.getConnection(dbURL, userName, password);
	}
	
}
