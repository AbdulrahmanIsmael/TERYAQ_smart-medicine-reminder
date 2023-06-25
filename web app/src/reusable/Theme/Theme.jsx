import { createTheme } from '@mui/material/styles';

const theme = createTheme({
  palette: {
    mode: 'light',
    primary: {
      main: '#2c3333',
      light: '#00ADB5',
    },
    secondary: {
      main: '#2c3333',
    },
    background: {
      paper: '#00ADB5',
      default: '#eee',
    },
    text: {
      primary: '#2c3333',
    },
    error: {
      main: '#EB455F',
    },
  },
});
export default theme;
