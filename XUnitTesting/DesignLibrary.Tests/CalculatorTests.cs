using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using DesignLibrary;
using Xunit;

namespace DesignLibrary.Tests
{
    public class CalculatorTests
    {
        [Theory]
        [InlineData(4,3,7)]
        [InlineData(21, 5.25, 26.25)]
        [InlineData(double.MaxValue, 5, double.MaxValue)]
        [InlineData(5, double.MaxValue, double.MaxValue)]
        public void Add_ShouldPass_SimpleValues(double x, double y, double expected)
        {
            double actual = Calculator.Add(x, y);
            Assert.Equal(expected, actual);
        }

        [Theory]
        [InlineData(8, 4, 2)]
        [InlineData(4, 8, 0.5)]
        public void Divide_ShouldPass_SimpleValues(double x, double y, double expected)
        {
            double actual = Calculator.Divide(x, y);
            Assert.Equal(expected, actual);
        }

        [Fact]
        public void Divide_ShouldPass_DivideByZeroThrowsArgumentException()
        {
            Assert.Throws<ArgumentException>("y", () => Calculator.Divide(8, 0));
        }

        [Fact]
        public void Divide_ShouldFail_DivideByZeroThrowsDivideByZeroException()
        {
            Assert.Throws<DivideByZeroException>(() => Calculator.Divide(8, 0));
        }

        [Fact]
        public void Divide_ShouldFail_DivideByZeroReturnsInf()
        {
            double expected = double.PositiveInfinity;
            double actual = Calculator.Divide(8, 0);
            Assert.Equal(expected, actual);
        }
    }
}
