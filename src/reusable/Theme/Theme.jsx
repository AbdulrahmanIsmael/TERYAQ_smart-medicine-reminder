import { createTheme } from '@mui/material/styles';

const theme = createTheme({
  palette: {
    mode: 'light',
    primary: {
      main: '#2e4f4f',
      light: '#00ADB5',
    },
    secondary: {
      main: '#00ADB5',
    },
    background: {
      paper: '#00ADB5',
      default: '#cbe4de',
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
