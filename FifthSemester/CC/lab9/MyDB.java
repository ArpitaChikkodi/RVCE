package com.amazonaws.samples;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.List;

import com.amazonaws.regions.Regions;
import com.amazonaws.services.rds.AmazonRDS;
import com.amazonaws.services.rds.AmazonRDSClientBuilder;
import com.amazonaws.services.rds.model.DBInstance;
import com.amazonaws.services.rds.model.DescribeDBInstancesResult;

public class MyDB {

	public static void main(String[] args)  {
		
		AmazonRDS awsRds = AmazonRDSClientBuilder.standard().withRegion(Regions.AP_SOUTH_1).build();
		
		DescribeDBInstancesResult dbInstanceResult = awsRds.describeDBInstances();
		
		List<DBInstance> dbInstance = dbInstanceResult.getDBInstances();
		
		for(DBInstance dbInst:dbInstance) {
			//System.out.println("DB Instance : "+dbInst);
			System.out.println("DB Instance : "+dbInst.getDBName());
		}
		
		String hostname = "dbm.cvjhqke4nmzi.ap-south-1.rds.amazonaws.com";
		String port = "3306";
		String JDBC_URL = "jdbc:mysql//"+hostname+":"+port+"/demo";
		
		try
		{
		Connection con = DriverManager.getConnection(JDBC_URL,"root","root1234");
		Statement stmt = con.createStatement();
		ResultSet result = stmt.executeQuery("Select * from emp");
		
		while(result.next()) {
			String id = result.getString(1);
			String name = result.getString(2);
			System.out.println("Id : "+id+"\nName : "+name);
		}
		
		}
		catch(SQLException e) {
			e.printStackTrace();
		}
		
		
		
	}

}
