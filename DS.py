import pandas as pd 

# 1: Import the dataset
df = pd.read_csv('WorldHits.csv')

# 2: Display basic information
print(f"Number of rows: {df.shape[0]}")
print(f"Number of columns: {df.shape[1]}")

# First five rows
print("First five rows:")
print(df.head())

# Total size of the dataset
print(f"Total size of the dataset: {df.size}")

# Number of missing values
print("Number of missing values:")
print(df.isnull().sum())

# 3: Display summary statistics
print("Sum of numerical columns:")
print(df.sum(numeric_only=True))

print("Average of numerical columns:")
print(df.mean(numeric_only=True))

print("Minimum values of numerical columns:")
print(df.min(numeric_only=True))

print("Maximum values of numerical columns:")
print(df.max(numeric_only=True))